#include "riscv/cpu.hpp"
#include <stdexcept>

namespace riscv {
CPU::CPU(Memory& memory) : memory_(memory) { reset(); }
void CPU::reset() { regs_.fill(0); pc_ = 0; }
std::uint32_t CPU::reg(unsigned index) const {
    if (index >= regs_.size()) throw std::out_of_range("register index");
    return regs_[index];
}
void CPU::write_reg(unsigned index, std::uint32_t value) {
    if (index != 0) regs_[index] = value;
}
void CPU::step() {
    const auto instruction = memory_.load32(pc_);
    const auto opcode = instruction & 0x7fu;
    const auto rd = (instruction >> 7) & 0x1fu;
    const auto funct3 = (instruction >> 12) & 0x7u;
    const auto rs1 = (instruction >> 15) & 0x1fu;
    const auto rs2 = (instruction >> 20) & 0x1fu;
    const auto funct7 = (instruction >> 25) & 0x7fu;

    if (opcode == 0x13u && funct3 == 0u) { // ADDI
        const auto immediate = static_cast<std::uint32_t>(
            static_cast<std::int32_t>(instruction) >> 20);
        write_reg(rd, regs_[rs1] + immediate);
    } else if (opcode == 0x33u && funct3 == 0u && funct7 == 0x00u) { // ADD
        write_reg(rd, regs_[rs1] + regs_[rs2]);
    } else if (opcode == 0x33u && funct3 == 0u && funct7 == 0x20u) { // SUB
        write_reg(rd, regs_[rs1] - regs_[rs2]);
    } else {
        throw std::runtime_error("unsupported RISC-V instruction");
    }
    pc_ += 4;
}
}
