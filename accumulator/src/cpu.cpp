#include "stdio.h"
#include "stdlib.h"
#include "cpu.hpp"
#include "memory.hpp"
#include "debug_helpers.hpp"
#include "bit_operations.hpp"
#include <iostream>

constexpr const char* ANSWER_SYMBOL = "ANS";
constexpr const char* LOAD_INSTRUCTION = "LOAD";
constexpr const char* STO_INSTRUCTION = "STO";
constexpr const char* ADD_INSTRUCTION = "ADD";
constexpr const char* MULT_INSTRUCTION = "MUL";
constexpr const char* END_INSTRUCTION = "END";
constexpr int32_t ANSWER_BIT_STREAM = computeBitStream(ANSWER_SYMBOL);
constexpr int32_t LOAD_INSTRUCTION_BIT_STREAM = computeBitStream(LOAD_INSTRUCTION);
constexpr int32_t STO_INSTRUCTION_BIT_STREAM = computeBitStream(STO_INSTRUCTION);
constexpr int32_t ADD_INSTRUCTION_BIT_STREAM = computeBitStream(ADD_INSTRUCTION);
constexpr int32_t MULT_INSTRUCTION_BIT_STREAM = computeBitStream(MULT_INSTRUCTION);
constexpr int32_t END_INSTRUCTION_BIT_STREAM = computeBitStream(END_INSTRUCTION);

void executeInstruction(MIPSCPU& cpu) 
{
    switch ((readContents(cpu.pc))) 
    {
        case LOAD_INSTRUCTION_BIT_STREAM:
            load(cpu);
            break;
        case STO_INSTRUCTION_BIT_STREAM:
            store(cpu);
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

void load(MIPSCPU& cpu) 
{
    writeContents(cpu.accumulator, readContents(cpu.memory.symbol_table[readContents(++cpu.pc)]));
}

void store(MIPSCPU& cpu) 
{
    writeContents(cpu.memory.symbol_table[readContents(++cpu.pc)], *cpu.accumulator);
}

void add(MIPSCPU& cpu) 
{
    writeContents(cpu.accumulator, readContents(cpu.accumulator) + readContents(cpu.memory.symbol_table[readContents(++cpu.pc)]));
}

void mult(MIPSCPU& cpu) 
{
    writeContents(cpu.accumulator, readContents(cpu.accumulator) * readContents(cpu.memory.symbol_table[readContents(++cpu.pc)]));
}

void end(MIPSCPU& cpu) 
{
    std::cout << "Quadratic Evaluation of Given Operands is " << readContents(cpu.memory.symbol_table[ANSWER_BIT_STREAM]) << "\n";
    exit(EXIT_SUCCESS);
}