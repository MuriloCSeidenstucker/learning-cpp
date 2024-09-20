cmake_minimum_required(VERSION 3.10)  # Defina a versão mínima do CMake

set(CMAKE_CXX_STANDARD 14)            # Defina a versão do C++

# Adicione os diretórios de origem
include_directories(src)

# Liste os arquivos fonte
set(SOURCES
    src/main.cpp
    src/cpu/cpu.cpp
    src/memory/memory.cpp
)

# Adicione o executável
add_executable(emulator ${SOURCES})