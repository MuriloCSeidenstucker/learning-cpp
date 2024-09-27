#ifndef NOP_INSTRUCTION_HPP
#define NOP_INSTRUCTION_HPP

#include "memory/memory.hpp"
#include "instruction.hpp"
#include "cpu/cpu.hpp"


class NOPInstruction : public Instruction
{
public:
    void execute(CPU& cpu, Memory& memory) override;
};

#endif
