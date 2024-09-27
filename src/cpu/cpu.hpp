#ifndef CPU_HPP
#define CPU_HPP

#include <map>
#include <memory>
#include "instruction.hpp"

class Memory; // Declaração forward da classe Memory
class Instruction;

class CPU
{
public:
    CPU();
    void cycle(Memory& memory); // Função que recebe referência à Memory

    // Getters para testes e manipulação de registradores
    unsigned char getA() const { return A; }
    void setA(unsigned char value) { A = value; }

    unsigned char getF() const { return F; }
    void setF(unsigned char value) { F = value; }

    unsigned char getB() const { return B; }
    void setB(unsigned char value) { B = value; }

    unsigned char getC() const { return C; }
    void setC(unsigned char value) { C = value; }

    unsigned char getD() const { return D; }
    void setD(unsigned char value) { D = value; }

    unsigned char getE() const { return E; }
    void setE(unsigned char value) { E = value; }

    unsigned char getH() const { return H; }
    void setH(unsigned char value) { H = value; }

    unsigned char getL() const { return L; }
    void setL(unsigned char value) { L = value; }

    unsigned short getPC() const { return PC; }
    void incrementPC(unsigned short value = 1) { PC += value; }

    unsigned short getSP() const { return SP; }

private:
    unsigned char A, F, B, C, D, E, H, L; // Registradores
    unsigned short PC, SP;                // Program Counter (PC) e Stack Pointer (SP)

    // Mapeamento de opcodes para instruções
    std::map<unsigned char, std::unique_ptr<Instruction>> opcodeMap;

    // Método para inicializar o mapa de opcodes
    void initializeOpcodeMap();
};

#endif