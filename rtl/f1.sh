#!/bin/sh

rm -rf obj_dir
rm -f top.vcd

verilator -Wall --cc --trace top.sv --exe ../tb/f1.cpp

make -j -C obj_dir/ -f Vtop.mk Vtop

obj_dir/Vtop