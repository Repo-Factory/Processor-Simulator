#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "memory.hpp"

// MIPS CPU structure
struct MIPSCPU 
{
    Memory memory;
    int32_t* pc = memory.userTextPtr;    
};

void push(MIPSCPU& cpu);
void pop(MIPSCPU& cpu);
void add(MIPSCPU& cpu);
void mult(MIPSCPU& cpu);
void end(MIPSCPU& cpu);

void executeInstruction(MIPSCPU& cpu);
