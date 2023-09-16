#include "memory.hpp"

int32_t getContents(int32_t* address)
{
    return *address;
}

void writeContents(int32_t* address, const int32_t data)
{
    *address = data;
}