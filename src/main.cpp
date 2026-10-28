#include "riscv/cpu.hpp"
#include <iostream>

int main() {
    riscv::Memory memory(64 * 1024);
    // addi x1, x0, 5; addi x2, x0, 7; add x3, x1, x2
    memory.store32(0, 0x00500093);
    memory.store32(4, 0x00700113);
    memory.store32(8, 0x002081b3);

    riscv::CPU cpu(memory);
    for (int i = 0; i < 3; ++i) cpu.step();
    std::cout << "x3 = " << cpu.reg(3) << " (expected 12)\n";
    return cpu.reg(3) == 12 ? 0 : 1;
}
