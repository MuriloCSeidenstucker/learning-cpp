#ifndef INC_DEC_INSTRUCTIONS_HPP
#define INC_DEC_INSTRUCTIONS_HPP

#include "instruction.hpp"
#include "cpu/cpu.hpp"
#include "memory/memory.hpp"
#include <iostream>

class INCInstruction : public Instruction
{
public:
    explicit INCInstruction(unsigned char& reg) : reg_(reg) {}

    void execute(CPU& cpu, Memory& memory) override
    {
        reg_++;
        std::cout << "INC " << static_cast<void*>(&reg_) << ": " << std::hex << static_cast<int>(reg_) << std::endl;
        cpu.incrementPC();
    }

private:
    unsigned char& reg_;
};

class DECInstruction : public Instruction
{
public:
    explicit DECInstruction(unsigned char& reg) : reg_(reg) {}

    void execute(CPU& cpu, Memory& memory) override
    {
        reg_--;
        std::cout << "DEC " << static_cast<void*>(&reg_) << ": " << std::hex << static_cast<int>(reg_) << std::endl;
        cpu.incrementPC();
    }

private:
    unsigned char& reg_;
};

#endif