#include <gtest/gtest.h>
#include "cpu/cpu.hpp"
#include "memory/memory.hpp"

// Testa se os registradores são inicializados corretamente
TEST(CPUTest, RegistersInitialization) {
    CPU cpu;
    EXPECT_EQ(cpu.getA(), 0);
    EXPECT_EQ(cpu.getF(), 0);
    EXPECT_EQ(cpu.getB(), 0);
    EXPECT_EQ(cpu.getC(), 0);
    EXPECT_EQ(cpu.getD(), 0);
    EXPECT_EQ(cpu.getE(), 0);
    EXPECT_EQ(cpu.getH(), 0);
    EXPECT_EQ(cpu.getL(), 0);
    EXPECT_EQ(cpu.getPC(), 0x0100);  // Verifica se o PC é inicializado corretamente
    EXPECT_EQ(cpu.getSP(), 0xFFFE);  // Verifica se o SP é inicializado corretamente
}

// Testa se o ciclo da CPU funciona corretamente
TEST(CPUTest, CycleExecution) {
    CPU cpu;
    Memory memory;

    cpu.cycle(memory);
    // Verifique se a execução do ciclo está correta com base nos opcodes executados
}
