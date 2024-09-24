#ifndef MEMORY_HPP
#define MEMORY_HPP

#include <string>

class Memory
{
public:
    Memory();                                                // Construtor
    unsigned char read(unsigned short address);              // Leitura de memória
    void write(unsigned short address, unsigned char value); // Escrita de memória
    bool loadROM(const std::string& filename);               // Função para carregar a ROM

private:
    unsigned char memory[0x10000]; // O Game Boy tem 64KB de espaço de endereçamento
};

#endif