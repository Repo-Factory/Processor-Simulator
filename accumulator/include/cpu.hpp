#include "stdio.h"
#include "stdlib.h"

#define NUM_REGISTERS 32
#define MEMORY_SIZE 1024
#define PC_COUNTER_INIT 0

void load() 
{

}

void sto() 
{

}

void add() 
{

}

void mult() 
{

}

void end() 
{
    exit(EXIT_SUCCESS);
}
 
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
    MIPSInstruction curr_instruction;
};

constexpr unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + (*str++);
    }
    return hash;
}

void executeInstruction(MIPSInstruction& instruction, MIPSCPU& cpu) {
    switch (hash(instruction.opcode)) {
        case hash("load"):
            load();
            break;
        case hash("sto"):
            sto();
            break;
        case hash("ADD"):
            add();
            break;
        case hash("MULT"):
            mult();
            break;
        case hash("END"):
            end();
            break;
        default:
            cpu.pc++;
            break;
    }
}

void execute()
{
    MIPSCPU cpu;
    MIPSInstruction* instruction;

    while (true) {
        scanf("%s", instruction);
        executeInstruction(*instruction, cpu);
    }

}