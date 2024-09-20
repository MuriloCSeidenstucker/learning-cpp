#include "memory.hpp"

// Construtor da Memória
Memory::Memory()
{
    // Inicializa toda a memória com zero
    for (int i = 0; i < 0x10000; i++)
    {
        memory[i] = 0;
    }
}

// Leitura de memória
unsigned char Memory::read(unsigned short address)
{
    return memory[address];
}

// Escrita de memória
void Memory::write(unsigned short address, unsigned char value)
{
    memory[address] = value;
}