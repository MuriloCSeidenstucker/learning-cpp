#include <iostream>
#include "cpu/cpu.hpp"
#include "memory/memory.hpp"

int main() {
    CPU cpu;
    Memory memory;

    std::cout << "Emulador de Game Boy iniciado!" << std::endl;

    // Simulação de ROM carregada na memória
    memory.write(0x0100, 0x3E); // Opcode LD A, n
    memory.write(0x0101, 0x42); // Valor imediato 0x42
    memory.write(0x0102, 0x3C); // Opcode INC A
    memory.write(0x0103, 0x00); // Opcode NOP

    int count = 0;
    while (true)
    {
        cpu.cycle(memory);
        count++;
        if (count == 4)
        {
            break;
        }
    }

    std::cout << "Emulador de Game Boy finalizado!" << std::endl;
    return 0;
}