#include "memory.hpp"

int32_t getContents(Memory& memory)
{
    return *memory.currentAddressPtr;
}

void writeContents(Memory& memory, int32_t data)
{
    *memory.currentAddressPtr = data;
}