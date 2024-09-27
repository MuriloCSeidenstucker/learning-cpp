cmake_minimum_required(VERSION 3.10)  # Defina a versão mínima do CMake

project(GameBoyEmulator)

set(CMAKE_CXX_STANDARD 14)            # Defina a versão do C++

# Adicione os diretórios de origem
include_directories(src)
include_directories(${CMAKE_SOURCE_DIR}/include)  # Diretório include da SDL2

# Diretório de instruções
file(GLOB INSTRUCTION_SOURCES "src/instructions/*.cpp")

# Liste os arquivos fonte
set(SOURCES
    src/main.cpp
    src/cpu/cpu.cpp
    src/memory/memory.cpp
    ${INSTRUCTION_SOURCES}  # Adicione as instruções
)

# Adicione o executável do emulador
add_executable(emulator ${SOURCES})

# Link com a biblioteca SDL2
link_directories(${CMAKE_SOURCE_DIR}/lib)  # Diretório lib da SDL2
target_link_libraries(emulator ${CMAKE_SOURCE_DIR}/lib/libSDL2main.a ${CMAKE_SOURCE_DIR}/lib/libSDL2.a)

# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Adicione o executável de testes
add_executable(emulator_tests
    tests/test_cpu.cpp
    tests/test_memory.cpp
)

# Adicione as mesmas fontes do emulador (CPU e Memory) e instruções aos testes
target_sources(emulator_tests PRIVATE
    src/cpu/cpu.cpp
    src/memory/memory.cpp
    ${INSTRUCTION_SOURCES}
)

# Link do Google Test com o executável de teste
target_link_libraries(emulator_tests gtest gtest_main)

# Adicione os testes ao CTest
add_test(NAME emulator_tests COMMAND emulator_tests)
