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
    int pc = PC_COUNTER_INIT;     // Program counter
    int IF_ID; // Instruction fetched in IF stage
    MIPSInstruction ID_EX; // Instruction decoded in ID stage
    int EX_MEM; // Execution result in EX stage
    int MEM_WB; // Memory access result in MEM stage
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
        case hash("LOAD"):
            load();
            break;
        case hash("STO"):
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