#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

namespace riscv {
class Memory {
public:
    explicit Memory(std::size_t size_bytes);
    [[nodiscard]] std::uint8_t load8(std::uint32_t address) const;
    [[nodiscard]] std::uint32_t load32(std::uint32_t address) const;
    void store8(std::uint32_t address, std::uint8_t value);
    void store32(std::uint32_t address, std::uint32_t value);
    [[nodiscard]] std::size_t size() const noexcept { return bytes_.size(); }
private:
    void check_range(std::uint32_t address, std::size_t width) const;
    std::vector<std::uint8_t> bytes_;
};
}
