#!/bin/sh

# Cleanup
rm -rf obj_dir
rm -f top.vcd

# Run Verilator to translate Verilog into C++, including C++ testbench
verilator -Wall --cc --trace top.sv mux.sv PCReg.sv PRegFetch.sv fakeinstmem.sv --exe top_tb.cpp

# Build C++ project via make automatically generated by Verilator
make -j -C obj_dir/ -f Vtop.mk Vtop

# Run executable simulation file
obj_dir/Vtop