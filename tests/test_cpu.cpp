#include "riscv/cpu.hpp"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <stdexcept>

int main() {
    riscv::Memory mem(4096);
    riscv::CPU cpu(mem);
    // ADDI x1, x0, -1; ADDI x2, x0, 7; ADD x3, x1, x2; SUB x4, x2, x3
    mem.store32(0, 0xfff00093);
    mem.store32(4, 0x00700113);
    mem.store32(8, 0x002081b3);
    mem.store32(12, 0x40310233);
    // ADDI x0, x2, 9 (must not modify x0)
    mem.store32(16, 0x00910013);
    for (int i = 0; i < 5; ++i) cpu.step();
    assert(cpu.reg(1) == UINT32_MAX);
    assert(cpu.reg(2) == 7);
    assert(cpu.reg(3) == 6);
    assert(cpu.reg(4) == 1);
    assert(cpu.reg(0) == 0);
    assert(cpu.pc() == 20);
    cpu.reset();
    assert(cpu.pc() == 0 && cpu.reg(3) == 0);
    bool threw = false;
    try { (void)mem.load32(4096); } catch (const std::out_of_range&) { threw = true; }
    assert(threw);
    std::cout << "All CPU tests passed\n";
}
