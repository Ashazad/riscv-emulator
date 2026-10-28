# Development Roadmap

## Milestone 1 — Core CPU (starter)
- [x] Registers, PC, and x0 semantics
- [x] ADD, ADDI, SUB
- [x] Little-endian memory
- [x] CMake and tests

## Milestone 2 — RV32I instruction coverage
- [ ] Logical, shift, comparison operations
- [ ] Loads/stores and sign extension
- [ ] Branches, JAL, JALR, LUI, AUIPC
- [ ] Instruction decoding edge cases

## Milestone 3 — Firmware execution
- [ ] Raw binary loader and memory map
- [ ] UART peripheral (MMIO)
- [ ] Timer and basic trap support

## Milestone 4 — Tooling
- [ ] Instruction traces and CLI flags
- [ ] Differential tests against a reference emulator
- [ ] Benchmarks with reproducible methodology
- [ ] GDB remote protocol support (optional)
