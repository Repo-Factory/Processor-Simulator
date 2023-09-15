#include "loader.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cctype>
#include <map>
#include <regex>

#define LABEL_REGEX_PATTERN "([A-Za-z][A-Za-z]*:)"
#define INT_REGEX_PATTERN "[0-9]"

namespace
{
    std::ostream& operator<<(std::ostream& stream, std::map<std::string, int32_t*>& table)
    {
        for (const auto& [symbol, address] : table)
        {
            stream << symbol << " " << *address << std::endl;
        }
        return stream;
    }

    void handleFileError(std::ifstream& stream, char* file)
    {
        if (!stream) {
            std::cerr << "Failed to open file: " << file << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    int32_t stringToBitStream(std::string& word)
    {
        const char* c_word = word.c_str();
        int32_t bitStream = 0;
        while (*c_word != '\0') {
            bitStream = (bitStream << 8) | static_cast<int8_t>(*c_word);
            c_word++;
        }
        return bitStream;
    }

    std::string int32ToAscii(int32_t intValue) 
    {
        std::string ascii;
        for (int i = 0; i < 4; ++i) {
            char byte = static_cast<char>((intValue >> (i * 8)) & 0xFF);
            ascii = byte + ascii;
        }
        return ascii;
    }

    void debugPrint(Memory& memory)
    {
        for (int i = 0; i < 512; ++i) {
            std::cout << "Memory[" << i << "]: " << int32ToAscii(*((int32_t*)&memory + i)) << std::endl;
        }
        for (int i = 0; i < 512; ++i) {
            std::cout << "Memory[" << i << "]: " <<  *((int32_t*)&memory + i) << std::endl;
        }
        std::cout << memory.symbol_table;
    }

    void handleWord(Memory& memory, std::string& word)
    { 
        if (std::regex_match(word, std::regex(LABEL_REGEX_PATTERN))) {
            memory.symbol_table.insert({word, memory.currentAddressPtr});
            return;
        }
        if (std::regex_match(word, std::regex(INT_REGEX_PATTERN))) {
            writeContents(memory, std::stoi(word));
            memory.currentAddressPtr++;
            return;        
        }
        if (word == ".data") {
            memory.currentAddressPtr = memory.userDataPtr;
            return;
        }
        if (word == ".text") {
            memory.currentAddressPtr = memory.userTextPtr;
            return;
        }
        writeContents(memory, stringToBitStream(word));
        memory.currentAddressPtr++;
    }

    void iterateFile(Memory& memory, std::ifstream& sourceCode, std::string& word)
    {
        while (!sourceCode.eof()) {
            if (sourceCode.peek() == '#') {
                std::getline(sourceCode, word);
                continue;
            }
            sourceCode >> word;
            handleWord(memory, word);
        }
    }
}

void load(Memory& memory, char* assemblyPath)
{
    std::ifstream sourceCode(assemblyPath);
    handleFileError(sourceCode, assemblyPath);
    std::string word;
    iterateFile(memory, sourceCode, word);
    debugPrint(memory);
    sourceCode.close();
}  


 