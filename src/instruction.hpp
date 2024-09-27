#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

class CPU;
class Memory;

class Instruction
{
public:
    virtual ~Instruction() = default;
    virtual void execute(CPU& cpu, Memory& memory) = 0; // Método virtual puro
};

#endif