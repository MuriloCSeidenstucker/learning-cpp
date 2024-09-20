#include "cpu.hpp"
#include <iostream>

CPU::CPU() {
    // Inicializar os registradores com valores padrão
    A = F = B = C = D = E = H = L = 0;
    PC = 0x0100; // O Game Boy incia a execução no endereço 0x0100
    SP = 0xFFFE; // Stack Pointer começa no topo da RAM
}

// Função que simula um ciclo da CPU
void CPU::cycle() {
    // Placeholder para emulação de instrução
    std::cout << "Executando ciclo da CPU..." << std::endl;
}