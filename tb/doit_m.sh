#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl")
OUTPUT_FOLDER=$(realpath "$SCRIPT_DIR/test_out")
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

GTEST_INCLUDE_PATH="/opt/homebrew/opt/googletest/include"
GTEST_LIB_PATH="/opt/homebrew/opt/googletest/lib"

passes=0
fails=0
if [[ ! -d $GTEST_INCLUDE_PATH || ! -d $GTEST_LIB_PATH ]]; then
    echo "${RED}Error: Google Test not found in expected paths!${RESET}"
    echo "Include path: $GTEST_INCLUDE_PATH"
    echo "Library path: $GTEST_LIB_PATH"
    exit 1
fi

if [[ $# -eq 0 ]]; then
    files=(${TEST_FOLDER}/*.cpp)
else
    files=("$@")
fi

cd $SCRIPT_DIR

rm -rf $OUTPUT_FOLDER/*
mkdir -p $OUTPUT_FOLDER

for file in "${files[@]}"; do
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-)

    if [[ $name == "verify.cpp" ]]; then
        name="top"
    fi

    echo "Running test for: ${file} -> ${name}"

    verilator   -Wall --trace \
                -cc ${RTL_FOLDER}/${name}.sv \
                --exe ${file} \
                -y ${RTL_FOLDER} \
                --prefix "Vdut" \
                -o Vdut \
                --Wno-fatal \
                -CFLAGS "-I${GTEST_INCLUDE_PATH}" \
                -LDFLAGS "-L${GTEST_LIB_PATH} -lgtest -lgtest_main -pthread"

    if [[ $? -ne 0 ]]; then
        echo "${RED}Error during Verilator translation for ${file}${RESET}"
        ((fails++))
        continue
    fi

    make -j -C obj_dir/ -f Vdut.mk
    if [[ $? -ne 0 ]]; then
        echo "${RED}Error during compilation for ${file}${RESET}"
        ((fails++))
        continue
    fi

    ./obj_dir/Vdut
    if [[ $? -eq 0 ]]; then
        echo "${GREEN}Test passed for ${file}${RESET}"
        ((passes++))
    else
        echo "${RED}Test failed for ${file}${RESET}"
        ((fails++))
    fi

    mv obj_dir $OUTPUT_FOLDER/$(basename "$file" .cpp)_output
done

echo "${GREEN}Passed: ${passes}${RESET}"
echo "${RED}Failed: ${fails}${RESET}"