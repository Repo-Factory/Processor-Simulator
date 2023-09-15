#include "stdio.h"
#include "stdlib.h"
#include "cpu.hpp"
#include "memory.hpp"

#define NUM_REGISTERS 32
#define PC_COUNTER_INIT 0

void push() 
{

}

void pop() 
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
 
constexpr unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + (*str++);
    }
    return hash;
}

void executeInstruction(MIPSInstruction& instruction, MIPSCPU& cpu) {
    switch (hash(instruction.opcode)) {
        case hash("PUSH"):
            push();
            break;
        case hash("POP"):
            pop();
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
    Memory memory;
    memory.userDataPtr;

}