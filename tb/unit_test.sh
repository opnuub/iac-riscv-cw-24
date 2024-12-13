#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <module_name>"
    exit 1
fi

MODULE_NAME=$1 
RTL_FOLDER=$(realpath "../rtl")
TB_FOLDER=$(realpath "../tests")
OUTPUT_DIR=$(realpath "./obj_dir")

mkdir -p ${OUTPUT_DIR}

if [ "$(uname -s)" == "Darwin" ]; then
    GTEST_INCLUDE="-isystem /opt/homebrew/Cellar/googletest/1.15.2/include"
    GTEST_LIB="-L/opt/homebrew/Cellar/googletest/1.15.2/lib"
    echo "Detected MacOS: Configuring for Darwin"
else
    GTEST_INCLUDE=""
    GTEST_LIB=""
    echo "Detected non-MacOS: Default configuration"
fi

verilator --cc ${RTL_FOLDER}/${MODULE_NAME}.sv \
          --exe ${TB_FOLDER}/${MODULE_NAME}_tb.sv ${TB_FOLDER}/${MODULE_NAME}_tb.cpp \
          --top-module ${MODULE_NAME} \
          -o ${OUTPUT_DIR}/V${MODULE_NAME} \
          -CFLAGS "${GTEST_INCLUDE}" \
          -LDFLAGS "${GTEST_LIB} -lgtest -lgtest_main"

if [ $? -ne 0 ]; then
    echo "Verilator compilation failed for module '${MODULE_NAME}'"
    exit 1
fi

make -j -C ${OUTPUT_DIR}/ -f V${MODULE_NAME}.mk VERBOSE=1

if [ $? -ne 0 ]; then
    echo "Make failed for module '${MODULE_NAME}'"
    exit 1
fi

${OUTPUT_DIR}/V${MODULE_NAME}

if [ $? -ne 0 ]; then
    echo "Test failed for module '${MODULE_NAME}'"
    exit 1
fi

echo "Test passed for module '${MODULE_NAME}'"