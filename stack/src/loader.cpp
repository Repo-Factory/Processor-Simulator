#include "loader.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>

namespace
{
    void handleFileError(std::ifstream& stream, char* file)
    {
        if (!stream) {
            std::cerr << "Failed to open file: " << file << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    void handleWord(Memory& memory, std::ifstream& sourceCode, std::string& word)
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
        if (word == "" || word[0] == '#')
            std::getline(sourceCode, word);
            return;
        if (word == ".data")
            memory.currentAddressPtr = memory.userDataPtr;
            return;
        if (word == ".text")
            memory.currentAddressPtr = memory.userTextPtr;
            return;
        writeContents(memory, static_cast<int32_t>(*word.c_str()));
        memory.currentAddressPtr++;
    }
}

void load(Memory& memory, char* assemblyPath)
{
    std::ifstream sourceCode(assemblyPath);
    handleFileError(sourceCode, assemblyPath);
    std::string word;
    while (sourceCode >> word) {
        // handleWord(memory, word);
        std::cout << word << std::endl;
    }
    sourceCode.close();
}   