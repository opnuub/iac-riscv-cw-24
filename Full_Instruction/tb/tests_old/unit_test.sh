#!/bin/bash


GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

GTEST_INCLUDE_PATH="/opt/homebrew/opt/googletest/include"
GTEST_LIB_PATH="/opt/homebrew/opt/googletest/lib"

if [[ $# -ne 1 ]]; then
    echo "${RED}Error: No module name provided.${RESET}"
    echo "Usage: ./unit_test.sh <ModuleName>"
    exit 1
fi


MODULE_NAME=$1
TB_SV="${MODULE_NAME}_tb.sv"
TB_CPP="${MODULE_NAME}_tb.cpp"
OUTPUT_DIR=$(realpath ./test_out)
RTL_DIR="../../rtl"

rm -rf $OUTPUT_DIR
mkdir -p $OUTPUT_DIR

#
if [[ ! -f $TB_SV ]]; then
    echo "${RED}Error: Testbench SystemVerilog file ${TB_SV} not found.${RESET}"
    exit 1
fi

if [[ ! -f $TB_CPP ]]; then
    echo "${RED}Error: Testbench C++ file ${TB_CPP} not found.${RESET}"
    exit 1
fi


echo "${YELLOW}Running test for ${MODULE_NAME}${RESET}"
echo "${YELLOW}Running test for ${MODULE_NAME}${RESET}"
verilator --cc $RTL_DIR/${MODULE_NAME}.sv \
          --top-module $MODULE_NAME \
          --trace \
          --exe $TB_CPP \
          --exe $TB_SV \
          --build \
          -CFLAGS "-I${GTEST_INCLUDE_PATH}" \
          -LDFLAGS "-L${GTEST_LIB_PATH} -lgtest -lgtest_main -pthread" \
          -o $OUTPUT_DIR/${MODULE_NAME}_sim

if [[ $? -ne 0 ]]; then
    echo "${RED}Error: Verilator compilation failed.${RESET}"
    exit 1
fi

$OUTPUT_DIR/${MODULE_NAME}_sim
if [[ $? -eq 0 ]]; then
    echo "${GREEN}Test passed for ${MODULE_NAME}${RESET}"
else
    echo "${RED}Test failed for ${MODULE_NAME}${RESET}"
    exit 1
fi