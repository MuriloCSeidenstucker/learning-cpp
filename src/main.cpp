#include <iostream>
#include "cpu/cpu.hpp"
#include "memory/memory.hpp"

int main() {
    CPU cpu;
    Memory memory;

    std::cout << "Emulador de Game Boy iniciado!" << std::endl;

    // Carrega a ROM
    if (!memory.loadROM("D:\\ROMs\\Tetris (JUE) (V1.1) [!].gb"))
    {
        return -1; // Sai se não conseguir carregar a ROM
    }
    

    int count = 0;
    while (true)
    {
        cpu.cycle(memory);
        count++;
        if (count == 100)
        {
            break;
        }
    }

    std::cout << "Emulador de Game Boy finalizado!" << std::endl;
    return 0;
}