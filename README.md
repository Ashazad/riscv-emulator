# RISC-V CPU Emulator (RV32I Starter)

A from-scratch **C++20** RISC-V emulator starter project for exploring low-level systems and embedded software. This is an **early-stage educational emulator**, not yet a complete RV32I implementation.

## Implemented

- 32 general-purpose 32-bit registers (`x0` is hardwired to zero)
- Program counter and fetch/decode/execute loop (`CPU::step()`)
- `ADDI`, `ADD`, `SUB` instruction execution
- Little-endian byte-addressable memory with 32-bit aligned access
- Simple executable demo and automated tests
- CMake builds and GitHub Actions CI

## Build and run

Requirements: C++20 compiler and CMake 3.20+.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/riscv_emulator
```

On Windows with Visual Studio generators, the executable may be at `build/Debug/riscv_emulator.exe`.

Expected output:

```text
x3 = 12 (expected 12)
```

## Layout

```text
include/riscv/   CPU and memory interfaces
src/             CPU, memory, and example program
tests/           Instruction and memory tests
docs/            Roadmap and design notes
.github/workflows/ Continuous integration
```

## Roadmap

1. Implement the remaining RV32I arithmetic, logical, branch, jump, and load/store instructions.
2. Add binary loading, execution limits, and richer illegal-instruction diagnostics.
3. Add memory-mapped UART and timer devices.
4. Add traps, CSRs, interrupts, and privilege behavior needed by selected firmware.
5. Add instruction tracing, reference comparisons, and performance benchmarks.
6. Optionally implement a GDB remote debugging stub.

## Scope and limitations

The initial demo loads three **hard-coded machine instructions**; there is no ELF or binary loader yet. Memory is a flat byte array, and no peripherals, interrupts, system calls, or OS are implemented. `CPU::step()` throws on unsupported instructions. This project is intended to grow through incremental, tested contributions.

## License

MIT — see [LICENSE](LICENSE).
