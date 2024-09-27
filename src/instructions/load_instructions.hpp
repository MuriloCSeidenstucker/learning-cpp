#ifndef LOAD_INSTRUCTIONS_HPP
#define LOAD_INSTRUCTIONS_HPP

#include "instruction.hpp"
#include "cpu/cpu.hpp"
#include "memory/memory.hpp"
#include <iostream>    

class LDImmediateInstruction : public Instruction
{
public:
    explicit LDImmediateInstruction(unsigned char& reg) : reg_(reg) {}

    void execute(CPU& cpu, Memory& memory) override
    {
        unsigned char value = memory.read(cpu.getPC() + 1);
        reg_ = value;
        std::cout << "LD " << static_cast<void*>(&reg_) << ", " << std::hex << static_cast<int>(value) << std::endl;
        cpu.incrementPC(2);
    }

private:
    unsigned char& reg_;
};

#endif