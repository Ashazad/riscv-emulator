#include "riscv/memory.hpp"
#include <stdexcept>

namespace riscv {
Memory::Memory(std::size_t size_bytes) : bytes_(size_bytes, 0) {}
void Memory::check_range(std::uint32_t address, std::size_t width) const {
    if (address > bytes_.size() || width > bytes_.size() - address)
        throw std::out_of_range("memory access out of bounds");
}
std::uint8_t Memory::load8(std::uint32_t address) const {
    check_range(address, 1);
    return bytes_[address];
}
std::uint32_t Memory::load32(std::uint32_t address) const {
    if (address % 4 != 0) throw std::invalid_argument("unaligned 32-bit load");
    check_range(address, 4);
    return static_cast<std::uint32_t>(bytes_[address]) |
           (static_cast<std::uint32_t>(bytes_[address + 1]) << 8) |
           (static_cast<std::uint32_t>(bytes_[address + 2]) << 16) |
           (static_cast<std::uint32_t>(bytes_[address + 3]) << 24);
}
void Memory::store8(std::uint32_t address, std::uint8_t value) {
    check_range(address, 1);
    bytes_[address] = value;
}
void Memory::store32(std::uint32_t address, std::uint32_t value) {
    if (address % 4 != 0) throw std::invalid_argument("unaligned 32-bit store");
    check_range(address, 4);
    for (unsigned i = 0; i < 4; ++i)
        bytes_[address + i] = static_cast<std::uint8_t>(value >> (8 * i));
}
}
