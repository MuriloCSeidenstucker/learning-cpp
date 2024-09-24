#ifndef CPU_HPP
#define CPU_HPP

class Memory; // Declaração forward da classe Memory

class CPU
{
public:
    CPU();
    void cycle(Memory& memory); // Função que recebe referência à Memory

    // Getters para testes
    unsigned char getA() const { return A; }
    unsigned short getPC() const { return PC; }

private:
    unsigned char A, F, B, C, D, E, H, L; // Registradores
    unsigned short PC, SP;                // Program Counter (PC) e Stack Pointer (SP)
};

#endif