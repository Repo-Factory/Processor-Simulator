#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "memory.hpp"

#define NUM_REGISTERS 32
#define MEMORY_SIZE 1024
#define PC_COUNTER_INIT 0

void push();
void pop();
void add();
void mult();
void end();

// MIPS instruction structure
struct MIPSInstruction {
    char* opcode;
    int rs;
    int rt;
    int rd;
    int immediate;
};

// MIPS CPU structure
struct MIPSCPU {
    int registers[NUM_REGISTERS];
    int memory[MEMORY_SIZE];
    int pc = PC_COUNTER_INIT;    
    MIPSInstruction instruction; 
};

constexpr unsigned int hash(const char* str);
void executeInstruction(MIPSInstruction& instruction, MIPSCPU& cpu);
void execute();