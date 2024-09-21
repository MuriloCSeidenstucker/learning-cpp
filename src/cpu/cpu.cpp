#include "cpu.hpp"
#include <memory/memory.hpp>
#include <iostream>

CPU::CPU()
{
    // Inicializar os registradores com valores padrão
    A = F = B = C = D = E = H = L = 0;
    PC = 0x0100; // O Game Boy incia a execução no endereço 0x0100
    SP = 0xFFFE; // Stack Pointer começa no topo da RAM
}

// Função que simula um ciclo da CPU
void CPU::cycle(Memory& memory)
{
    // Exemplo de leitura de memória na posição do PC
    unsigned char opcode = memory.read(PC);

    // Incrementar o PC para simular a leitura de uma instrução
    PC++;

    // Executa a instrução baseada no opcode
    switch (opcode)
    {
    case 0x00: // NOP
        // Não faz nada, apenas imprime uma mensagem para debug
        std::cout << "NOP (No Operation)" << std::endl;
        break;
    
    case 0x3E: // LD A, n
    {
        // Lê o próximo byte da memória (valor imediato)
        unsigned char value = memory.read(PC);
        PC++; // Avança o PC após ler o valor imediato
        A = value;
        std::cout << "LD A, " << std::hex << (int)value << std::endl;
        break;
    }
    case 0x3C: // INC A
        A++;
        std::cout << "INC A -> " << std::hex << (int)A << std::endl;
        break;
    default:
        std::cout << "Opcode desconhecido: " << std::hex << (int)opcode << std::endl;
        break;
    }

    // Placeholder: você pode adicionar lógica real de instruções aqui
    // Incrementar contador de ciclo (simulando tempo de execução)
    // Exemplo: se for NOP, não faz nada, apenas incrementa o PC
}