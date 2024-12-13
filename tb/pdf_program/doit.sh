#!/bin/bash

# Usage: ./doit.sh <file.mem>

input_file=$1

rm -rf obj_dir
rm -f top.vcd
rm -rf ../tb

../assemble.sh pdf.s
mkdir ../tb
mv ../program.hex ../tb
touch ../tb/data.hex
cp ../reference/$1 ../tb/data.hex

cd ../../rtl
verilator -Wall --cc --trace top.sv --exe top_tb.cpp
mv obj_dir ../tb/pdf_program

cd ../tb/pdf_program

make -j -C obj_dir/ -f Vtop.mk Vtop

obj_dir/Vtop