#include <verilated.h>
#include "VL2Cache.h"
#include <iostream>

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // Create instance of L2Cache
    VL2Cache* cache = new VL2Cache;

    // Initialize simulation inputs
    cache->clk = 0;
    cache->rst_n = 0;
    cache->load = 0;
    cache->store = 0;
    cache->address = 0;
    cache->data_in = 0;
    cache->mem_data = 0;
    cache->mem_ready = 0;

    // Simulation time
    int time = 0;

    // Clock toggle function
    auto toggle_clock = [&]() {
        cache->clk = !cache->clk;
        cache->eval();
    };

    // Reset
    while (time < 20) {
        cache->rst_n = (time >= 10); // Deassert reset after 10 time units
        toggle_clock();
        time++;
    }

    // Test 1: Load - Cache Miss
    cache->address = 0x00000000;
    cache->load = 1;
    toggle_clock();
    cache->load = 0;
    std::cout << "Test 1 - Cache Miss (Load): "
              << "Hit = " << (int)cache->hit << ", Miss = " << (int)cache->miss << "\n";

    // Test 2: Store - Cache Miss
    cache->address = 0x00000004;
    cache->data_in = 0xDEADBEEF;
    cache->store = 1;
    toggle_clock();
    cache->store = 0;
    std::cout << "Test 2 - Cache Miss (Store): "
              << "Hit = " << (int)cache->hit << ", Miss = " << (int)cache->miss << "\n";

    // Test 3: Load - Cache Hit
    cache->address = 0x00000004;
    cache->load = 1;
    toggle_clock();
    cache->load = 0;
    std::cout << "Test 3 - Cache Hit (Load): "
              << "Hit = " << (int)cache->hit << ", Miss = " << (int)cache->miss << "\n";

    // Test 4: Replacement
    cache->address = 0x00000040;
    cache->load = 1;
    toggle_clock();
    cache->load = 0;
    std::cout << "Test 4 - Cache Replacement: "
              << "Hit = " << (int)cache->hit << ", Miss = " << (int)cache->miss << "\n";

    // Clean up
    delete cache;
    return 0;
}