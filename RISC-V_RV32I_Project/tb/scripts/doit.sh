#!/bin/bash

# Detect the operating system
if [ "$(uname -s)" == "Darwin" ]; then
    GTEST_INCLUDE_DIR="/opt/homebrew/Cellar/googletest/1.15.2/include"
    GTEST_LIB_DIR="/opt/homebrew/Cellar/googletest/1.15.2/lib"
else
    GTEST_INCLUDE_DIR="/usr/local/include"
    GTEST_LIB_DIR="/usr/local/lib"
fi

# Constants
SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

# Variables
passes=0
fails=0

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # If no arguments provided, run all tests
    files=(${TEST_FOLDER}/*.cpp)
else
    # If arguments provided, use them as input files
    files=("$@")
fi

cd $SCRIPT_DIR

# Wipe previous test output
rm -rf test_out/*

# Iterate through files
for file in "${files[@]}"; do
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)

    # If verify.cpp -> we are testing the top module
    if [ "$name" == "verify.cpp" ]; then
        name="top"
    fi

    # Translate Verilog -> C++ including testbench
    verilator   -Wall --trace \
                -cc ${RTL_FOLDER}/${name}.sv \
                --exe ${file} \
                -y ${RTL_FOLDER} \
                --prefix "Vdut" \
                -o Vdut \
                -I${GTEST_INCLUDE_DIR} \
                -L${GTEST_LIB_DIR} \
                -lgtest -lgtest_main -lpthread

    # Build C++ project with automatically generated Makefile
    make -j -C obj_dir/ -f Vdut.mk

    # Run executable simulation file
    if ./obj_dir/Vdut; then
        echo "${GREEN}Test Passed: ${file}${RESET}"
        ((passes++))
    else
        echo "${RED}Test Failed: ${file}${RESET}"
        ((fails++))
    fi
done

# Save obj_dir in test_out
mv obj_dir test_out/

# Final summary
echo "Tests Passed: ${GREEN}${passes}${RESET}, Tests Failed: ${RED}${fails}${RESET}"