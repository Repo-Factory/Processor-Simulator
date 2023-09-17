#include "bit_operations.hpp"

#define INIT_BIT_STREAM 0
#define STRING_END_CHAR '\0'
#define LABEL_END_CHAR ':'
#define EIGHT_BITS 8

int32_t stringToBitStream(const std::string& word)
{
    const char* c_word = word.c_str();
    int32_t bitStream = INIT_BIT_STREAM;
    while (*c_word != STRING_END_CHAR) {
        bitStream = (bitStream << EIGHT_BITS) | static_cast<int8_t>(*c_word++);
    }
    return bitStream;
}

int32_t labelToBitStream(const std::string& label)
{
    const char* c_label = label.c_str();
    int32_t bitStream = INIT_BIT_STREAM;
    while (*c_label != LABEL_END_CHAR) {
        bitStream = (bitStream << EIGHT_BITS) | static_cast<int8_t>(*c_label++);
    }
    return bitStream;
}
