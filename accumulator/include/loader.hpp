#pragma once
#include "memory.hpp"

class Loader
{
    public:
        void loadProgram(Memory& memory, char* assemblyPath);
        void loadToMemory(Memory& memory, const std::string& word);
    private:
        int32_t* currentAddressPtr = nullptr;
};
