#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "memory.hpp"

struct MIPSCPU // CPU has memory and registers (in this case accumulator program counter) 
{
    Memory memory;
    bool userMode = false;
    int32_t* accumulator = new int();
    int32_t* pc = memory.userTextPtr;    
};

/* Functions which implement each instruction in simulator */
void load(MIPSCPU& cpu);
void store(MIPSCPU& cpu);
void add(MIPSCPU& cpu);
void mult(MIPSCPU& cpu);
void end(MIPSCPU& cpu);

/* Primary function called in loop from main to simulate machine */
void executeInstruction(MIPSCPU& cpu);
