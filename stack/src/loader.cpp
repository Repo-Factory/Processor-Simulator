#include "loader.hpp"
#include "debug_helpers.hpp"
#include "bit_operations.hpp"
#include "file_handling_helpers.hpp"
#include <regex>

#define LABEL_REGEX_PATTERN "([A-Za-z][A-Za-z]*:)"
#define INT_REGEX_PATTERN "[0-9]*"
#define DATA_SECTION_IDENTIFIER ".data"
#define TEXT_SECTION_IDENTIFIER ".text"
#define COMMENT_IDENTIFIER '#'

namespace
{
    void iterateFile(Loader* loader, Memory& memory, std::ifstream& sourceCode)
    {
        while (!sourceCode.eof()) 
        {
            if (sourceCode.peek() == COMMENT_IDENTIFIER) 
                getLine(sourceCode); // skip line
            else loader->loadToMemory(memory, getWord(sourceCode));
        }
    }
}

void Loader::loadToMemory(Memory& memory, const std::string& word)
{ 
    if (word == DATA_SECTION_IDENTIFIER)
        this->currentAddressPtr = memory.userDataPtr;

    else if (word == TEXT_SECTION_IDENTIFIER) 
        this->currentAddressPtr = memory.userTextPtr;

    else if (std::regex_match(word, std::regex(LABEL_REGEX_PATTERN)))
        memory.symbol_table.insert({labelToBitStream(word), this->currentAddressPtr});

    else if (std::regex_match(word, std::regex(INT_REGEX_PATTERN)))
        writeContents(this->currentAddressPtr++, std::stoi(word));
        
    else writeContents(this->currentAddressPtr++, stringToBitStream(word));
}

void Loader::loadProgram(Memory& memory, char* assemblyPath)
{
    std::ifstream sourceCode(assemblyPath);
    handleFileError(sourceCode, assemblyPath);
    iterateFile(this, memory, sourceCode);
    #ifdef DEBUG
        debugPrint(memory);
    #endif
    sourceCode.close();
}  
 