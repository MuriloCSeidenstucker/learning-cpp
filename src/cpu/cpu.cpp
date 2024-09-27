#include "cpu.hpp"
#include "instructions/nop_instruction.hpp"
#include "instructions/load_instructions.hpp"
#include "instructions/inc_dec_instructions.hpp"
#include <memory/memory.hpp>
#include <iostream>

CPU::CPU()
{
    // Inicializar os registradores com valores padrão
    A = F = B = C = D = E = H = L = 0;
    PC = 0x0100; // O Game Boy incia a execução no endereço 0x0100
    SP = 0xFFFE; // Stack Pointer começa no topo da RAM
    initializeOpcodeMap();  // Inicializa o mapeamento de opcodes
}

void CPU::initializeOpcodeMap()
{
    opcodeMap[0x00] = std::make_unique<NOPInstruction>(); //NOP
    opcodeMap[0x3E] = std::make_unique<LDImmediateInstruction>(A); // LD A, n
    opcodeMap[0x06] = std::make_unique<LDImmediateInstruction>(B); // LD B, n
    opcodeMap[0x0E] = std::make_unique<LDImmediateInstruction>(C); // LD C, n
    opcodeMap[0x16] = std::make_unique<LDImmediateInstruction>(D); // LD D, n
    opcodeMap[0x1E] = std::make_unique<LDImmediateInstruction>(E); // LD E, n
    opcodeMap[0x26] = std::make_unique<LDImmediateInstruction>(H); // LD H, n
    opcodeMap[0x2E] = std::make_unique<LDImmediateInstruction>(L); // LD L, n

    // Instruções de Incremento
    opcodeMap[0x3C] = std::make_unique<INCInstruction>(A); // INC A
    opcodeMap[0x04] = std::make_unique<INCInstruction>(B); // INC B
    opcodeMap[0x0C] = std::make_unique<INCInstruction>(C); // INC C
    opcodeMap[0x14] = std::make_unique<INCInstruction>(D); // INC D
    opcodeMap[0x1C] = std::make_unique<INCInstruction>(E); // INC E
    opcodeMap[0x24] = std::make_unique<INCInstruction>(H); // INC H
    opcodeMap[0x2C] = std::make_unique<INCInstruction>(L); // INC L

    // Instruções de Decremento
    opcodeMap[0x3D] = std::make_unique<DECInstruction>(A);  // DEC A
    opcodeMap[0x05] = std::make_unique<DECInstruction>(B);  // DEC B
    opcodeMap[0x0D] = std::make_unique<DECInstruction>(C);  // DEC C
    opcodeMap[0x15] = std::make_unique<DECInstruction>(D);  // DEC D
    opcodeMap[0x1D] = std::make_unique<DECInstruction>(E);  // DEC E
    opcodeMap[0x25] = std::make_unique<DECInstruction>(H);  // DEC H
    opcodeMap[0x2D] = std::make_unique<DECInstruction>(L);  // DEC L
}

// Função que simula um ciclo da CPU
void CPU::cycle(Memory& memory)
{
    // Lê o opcode atual da memória
    unsigned char opcode = memory.read(PC);

    if (opcodeMap.find(opcode) != opcodeMap.end())
    {
        opcodeMap[opcode]->execute(*this, memory); // Executa a instrução associada ao opcode
    } else
    {
        std::cout << "Opcode desconhecido: " << std::hex << (int)opcode << std::endl;
        PC++; // Avança o PC em caso de opcode desconhecido
    }
    

    // Placeholder: você pode adicionar lógica real de instruções aqui
    // Incrementar contador de ciclo (simulando tempo de execução)
    // Exemplo: se for NOP, não faz nada, apenas incrementa o PC
}