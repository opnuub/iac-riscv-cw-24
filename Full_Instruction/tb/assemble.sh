#!/bin/bash

# Usage: ./assemble.sh <file.s>

# Default vars
SCRIPT_DIR=$(dirname "$(realpath "$0")")
output_file="$SCRIPT_DIR/program.hex"
rtl_dir="$SCRIPT_DIR/../rtl"  # Adjust this to the actual RTL folder path

# Handle terminal arguments
if [ $# -eq 0 ]; then
    echo "Usage: ./assemble.sh <file.s>"
    exit 1
fi

input_file=$1
basename=$(basename "$input_file" | sed 's/\.[^.]*$//')
parent=$(dirname "$input_file")
file_extension="${input_file##*.}"
LOG_DIR="$SCRIPT_DIR/test_out/$basename"

# Create output directory for disassembly, hex, and waveforms
mkdir -p "$LOG_DIR"

# Assemble the file
riscv64-unknown-elf-as -R -march=rv32im -mabi=ilp32 -o "a.out" "$input_file"
riscv64-unknown-elf-ld -melf32lriscv -e 0xBFC00000 -Ttext 0xBFC00000 -o "a.out.reloc" "a.out"
riscv64-unknown-elf-objcopy -O binary -j .text "a.out.reloc" "a.bin"

rm *dis 2>/dev/null

# Generate a disassembly file for debugging
riscv64-unknown-elf-objdump -f -d --source -m riscv a.out.reloc > "${LOG_DIR}/program.dis"

# Generate the program.hex file
od -v -An -t x1 "a.bin" | tr -s '\n' | awk '{$1=$1};1' > "${output_file}"

# Remove old program.hex from the rtl directory and replace it
rm -f "$rtl_dir/program.hex"
cp "${output_file}" "$rtl_dir/program.hex"

# Clean up intermediate files
rm "a.out.reloc" "a.out" "a.bin"