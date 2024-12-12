#!/bin/sh

rm -rf obj_dir
rm -f f1.vcd
rm -rf ../tb

../assemble.sh f1_asm.s
mkdir ../tb
mv ../program.hex ../tb
touch ../tb/data.hex

cd ../../rtl

VERILOG_FILES=$(find ../tb/f1_program -name "*.sv")

verilator -Wall --cc --trace $VERILOG_FILES --exe f1_tb.cpp --top-module f1

mv obj_dir ../tb/f1_program

cd ../tb/f1_program

make -j -C obj_dir/ -f Vf1.mk Vf1

obj_dir/Vf1