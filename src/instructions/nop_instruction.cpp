#include "nop_instruction.hpp"
#include <iostream>

void NOPInstruction::execute(CPU& cpu, Memory& memory)
{
    std::cout << "NOP (No Operation)" << std::endl;
    cpu.incrementPC();
}
