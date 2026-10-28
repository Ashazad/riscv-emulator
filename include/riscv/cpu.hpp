#pragma once
#include "riscv/memory.hpp"
#include <array>
#include <cstdint>

namespace riscv {
class CPU {
public:
    explicit CPU(Memory& memory);
    void reset();
    void step();
    [[nodiscard]] std::uint32_t reg(unsigned index) const;
    [[nodiscard]] std::uint32_t pc() const noexcept { return pc_; }
    void set_pc(std::uint32_t address) noexcept { pc_ = address; }
private:
    void write_reg(unsigned index, std::uint32_t value);
    Memory& memory_;
    std::array<std::uint32_t, 32> regs_{};
    std::uint32_t pc_ = 0;
};
}
