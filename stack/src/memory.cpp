#include "memory.hpp"

int32_t getContents(Memory& memory)
{
    return *memory.currentAddressPtr;
}

void writeContents(Memory& memory, const int32_t data)
{
    *memory.currentAddressPtr = data;
}