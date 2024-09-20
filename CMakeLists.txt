cmake_minimum_required(VERSION 3.10)  # Defina a versão mínima do CMake

project(GameBoyEmulator)

set(CMAKE_CXX_STANDARD 14)            # Defina a versão do C++

# Adicione os diretórios de origem
include_directories(src)
include_directories(${CMAKE_SOURCE_DIR}/include)  # Diretório include da SDL2

# Liste os arquivos fonte
set(SOURCES
    src/main.cpp
    src/cpu/cpu.cpp
    src/memory/memory.cpp
)

# Adicione o executável
add_executable(emulator ${SOURCES})

# Link com a biblioteca SDL2
link_directories(${CMAKE_SOURCE_DIR}/lib)  # Diretório lib da SDL2
target_link_libraries(emulator ${CMAKE_SOURCE_DIR}/lib/libSDL2main.a ${CMAKE_SOURCE_DIR}/lib/libSDL2.a)
