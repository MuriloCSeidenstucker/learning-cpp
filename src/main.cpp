#include <iostream>
#include "cpu.hpp"
#include "memory.hpp"

int main() {
    CPU cpu;
    Memory memory;

    std::cout << "Emulador de Game Boy iniciado!" << std::endl;

    int count = 0;
    while (true)
    {
        cpu.cycle();
        count++;
        if (count == 5)
        {
            break;
        }
    }

    std::cout << "Emulador de Game Boy finalizado!" << std::endl;
    return 0;
}