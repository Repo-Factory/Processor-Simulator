#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "memory.hpp"

struct MIPSCPU  // CPU has memory and registers (in this case only program counter) 
{
    Memory memory;
    int32_t* pc = memory.userTextPtr;    
};

/* Functions which implement each instruction in simulator */
void push(MIPSCPU& cpu);
void pop(MIPSCPU& cpu);
void add(MIPSCPU& cpu);
void mult(MIPSCPU& cpu);
void end(MIPSCPU& cpu);

/* Primary function called in loop from main to simulate machine */
void executeInstruction(MIPSCPU& cpu);
