#!/bin/bash

# Check if module name is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <module_name>"
    exit 1
fi

MODULE_NAME=$1

# Define folders
RTL_FOLDER=$(realpath "../../rtl")
TB_FOLDER=$(realpath "../tests")
OUTPUT_DIR=$(realpath "./obj_dir")

# Create output directory if it doesn't exist
if [ ! -d "$OUTPUT_DIR" ]; then
    mkdir -p "$OUTPUT_DIR"
fi

# Set paths for GTest (assuming it's installed correctly)
GTEST_INCLUDE="/usr/include/gtest"
GTEST_LIB="/usr/lib"

# Ensure GTest libraries are in place
if [ ! -f "$GTEST_LIB/libgtest.a" ] || [ ! -f "$GTEST_LIB/libgtest_main.a" ]; then
    echo "Error: GTest libraries not found in $GTEST_LIB. Please ensure GTest is installed correctly."
    exit 1
fi

# Run Verilator
verilator --cc "$RTL_FOLDER/$MODULE_NAME.sv" \
    --exe "$TB_FOLDER/${MODULE_NAME}_tb.sv" "$TB_FOLDER/${MODULE_NAME}_tb.cpp" \
    --top-module "$MODULE_NAME" \
    -o "$OUTPUT_DIR/V$MODULE_NAME" \
    -CFLAGS "-I$GTEST_INCLUDE" \
    -LDFLAGS "-L$GTEST_LIB -lgtest -lgtest_main"

if [ $? -ne 0 ]; then
    echo "Verilator compilation failed for module '$MODULE_NAME'."
    exit 1
fi

# Run Make
make -j -C "$OUTPUT_DIR" -f "V$MODULE_NAME.mk" VERBOSE=1

if [ $? -ne 0 ]; then
    echo "Make failed for module '$MODULE_NAME'."
    exit 1
fi

# Execute the testbench
"$OUTPUT_DIR/V$MODULE_NAME"

if [ $? -ne 0 ]; then
    echo "Test failed for module '$MODULE_NAME'."
    exit 1
fi

echo "Test passed for module '$MODULE_NAME'."
