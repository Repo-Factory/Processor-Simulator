#include "stdio.h"
#include "stdlib.h"
#include "cpu.hpp"
#include "memory.hpp"
#include "debug_helpers.hpp"
#include "bit_operations.hpp"
#include <iostream>

constexpr const char* PUSH_INSTRUCTION = "PUSH";
constexpr const char* POP_INSTRUCTION = "POP";
constexpr const char* ADD_INSTRUCTION = "ADD";
constexpr const char* MULT_INSTRUCTION = "MUL";
constexpr const char* END_INSTRUCTION = "END";
constexpr int32_t PUSH_INSTRUCTION_BIT_STREAM = computeBitStream(PUSH_INSTRUCTION);
constexpr int32_t POP_INSTRUCTION_BIT_STREAM = computeBitStream(POP_INSTRUCTION);
constexpr int32_t ADD_INSTRUCTION_BIT_STREAM = computeBitStream(ADD_INSTRUCTION);
constexpr int32_t MULT_INSTRUCTION_BIT_STREAM = computeBitStream(MULT_INSTRUCTION);
constexpr int32_t END_INSTRUCTION_BIT_STREAM = computeBitStream(END_INSTRUCTION);

void executeInstruction(MIPSCPU& cpu) 
{
    switch ((readContents(cpu.pc))) 
    {
        case PUSH_INSTRUCTION_BIT_STREAM:
            push(cpu);
            break;
        case POP_INSTRUCTION_BIT_STREAM:
            pop(cpu);
            break;
        case ADD_INSTRUCTION_BIT_STREAM:
            add(cpu);
            break;
        case MULT_INSTRUCTION_BIT_STREAM:
            mult(cpu);
            break;
        case END_INSTRUCTION_BIT_STREAM:
            end(cpu);
            break;
    }
    cpu.pc++;
}

void push(MIPSCPU& cpu) 
{
    writeContents(++cpu.memory.stackPtr, readContents(cpu.memory.symbol_table[readContents(++cpu.pc)]));
}

void pop(MIPSCPU& cpu) 
{
    writeContents(cpu.memory.symbol_table[readContents(++cpu.pc)], *cpu.memory.stackPtr--);
}

void add(MIPSCPU& cpu) 
{
    writeContents(--cpu.memory.stackPtr, readContents(cpu.memory.stackPtr) + readContents(cpu.memory.stackPtr - 1));
}

void mult(MIPSCPU& cpu) 
{
    writeContents(--cpu.memory.stackPtr, readContents(cpu.memory.stackPtr) * readContents(cpu.memory.stackPtr - 1));
}

void end(MIPSCPU& cpu) 
{
    std::cout << cpu.memory.symbol_table;
    exit(EXIT_SUCCESS);
}