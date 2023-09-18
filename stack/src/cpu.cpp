/*
 *  @brief
 *          CPU related functions to execute instructions
 *
 * CPU will continually read contents at program counter
 * If the contents are a recognized instruction, it will execute
 * the appropriate program logic
 */

#include "stdio.h"
#include "stdlib.h"
#include "cpu.hpp"
#include "memory.hpp"
#include "debug_helpers.hpp"
#include "bit_operations.hpp"
#include <iostream>

/* Constexpr bit streams of strings calculated at compile time to run efficiently and work nicely in switch statement */
constexpr const char* ANSWER_SYMBOL                 =   "ANS";
constexpr const char* PUSH_INSTRUCTION              =   "PUSH";
constexpr const char* POP_INSTRUCTION               =   "POP";
constexpr const char* ADD_INSTRUCTION               =   "ADD";
constexpr const char* MULT_INSTRUCTION              =   "MUL";
constexpr const char* END_INSTRUCTION               =   "END";
constexpr int32_t ANSWER_BIT_STREAM                 =   computeBitStream(ANSWER_SYMBOL);
constexpr int32_t PUSH_INSTRUCTION_BIT_STREAM       =   computeBitStream(PUSH_INSTRUCTION);
constexpr int32_t POP_INSTRUCTION_BIT_STREAM        =   computeBitStream(POP_INSTRUCTION);
constexpr int32_t ADD_INSTRUCTION_BIT_STREAM        =   computeBitStream(ADD_INSTRUCTION);
constexpr int32_t MULT_INSTRUCTION_BIT_STREAM       =   computeBitStream(MULT_INSTRUCTION);
constexpr int32_t END_INSTRUCTION_BIT_STREAM        =   computeBitStream(END_INSTRUCTION);

/* Called in loop from main to run program */
void executeInstruction(MIPSCPU& cpu) 
{
    switch ((readContents(cpu.pc)))  // Read instruction at PC
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
    cpu.pc++;           // Always increment PC
}


////////////////////////////////////////////////////////////////////////////////////////////
/******* These functions will manipulate values on the stack to perform calculation *******/
////////////////////////////////////////////////////////////////////////////////////////////

/* Read contents of the succeeding symbol and place them where the stackPtr is, then incremenent stack ptr */
void push(MIPSCPU& cpu) 
{
    writeContents(++cpu.memory.stackPtr, readContents(cpu.memory.symbol_table[readContents(++cpu.pc)]));
}

/* Into the address of the succeeding symbol, write the contents of where the stackPtr is, then decrement stack ptr */
void pop(MIPSCPU& cpu) 
{
    writeContents(cpu.memory.symbol_table[readContents(++cpu.pc)], *cpu.memory.stackPtr--);
}

/* Get the contents of the current stackPtr and the element under it, then add them and place them where the stack ptr currently is  */
void add(MIPSCPU& cpu) 
{
    writeContents(--cpu.memory.stackPtr, readContents(cpu.memory.stackPtr) + readContents(cpu.memory.stackPtr - 1));
}

/* Get the contents of the current stackPtr and the element under it, then multiply them and place them where the stack ptr currently is  */
void mult(MIPSCPU& cpu) 
{
    writeContents(--cpu.memory.stackPtr, readContents(cpu.memory.stackPtr) * readContents(cpu.memory.stackPtr - 1));
}

/* Switch user mode to false to exit instruction loop */
void end(MIPSCPU& cpu) 
{
    std::cout << "Quadratic Evaluation of Given Operands is " << readContents(cpu.memory.symbol_table[ANSWER_BIT_STREAM]) << "\n";
    exit(EXIT_SUCCESS);
}