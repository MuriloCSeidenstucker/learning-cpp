#ifndef CPU_HPP
#define CPU_HPP

class CPU {
public:
    CPU();
    void cycle();

private:
    unsigned char A, F, B, C, D, E, H, L; //Registradores
    unsigned short PC, SP; // Program Counter (PC) e Stack Pointer (SP)
};

#endif