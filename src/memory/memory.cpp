#include "memory.hpp"
#include <fstream>
#include <iostream>

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

// Função para carregar ROM na memória
bool Memory::loadROM(const std::string& filename)
{
    std::ifstream romFile(filename, std::ios::binary);
    if (!romFile.is_open())
    {
        std::cerr << "Erro ao carregar a ROM: " << filename << std::endl;
        return false;
    }

    // Lê o arquivo ROM e carrega na memória a partir do endereço 0x0000
    romFile.read((char*)memory, 0x8000); // ROMs de Game Boy geralmente ocupam até 32KB
    if (romFile.gcount() == 0)
    {
        std::cerr << "ROM está vazia ou não foi lida corretamente." << std::endl;
        return false;
    }

    std::cout << "ROM carregada com sucesso: " << filename << std::endl;
    return true;
}