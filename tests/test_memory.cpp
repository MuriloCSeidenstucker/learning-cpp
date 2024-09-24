#include <gtest/gtest.h>
#include "memory/memory.hpp"

// Testa se a memória é inicializada corretamente
TEST(MemoryTest, MemoryInitialization) {
    Memory memory;
    EXPECT_EQ(memory.read(0x0000), 0);  // Verifica se a memória é inicializada com zeros
}

// Testa leitura e escrita na memória
TEST(MemoryTest, ReadWriteMemory) {
    Memory memory;
    memory.write(0x1234, 0x56);
    EXPECT_EQ(memory.read(0x1234), 0x56);  // Verifica se o valor foi escrito e lido corretamente
}
