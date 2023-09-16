#pragma once
#include <stdint.h>
#include <string>

#define INIT_BIT_STREAM 0
#define STRING_END_CHAR '\0'
#define EIGHT_BITS 8

int32_t labelToBitStream(const std::string& word);
int32_t stringToBitStream(const std::string& word);

constexpr int32_t computeBitStream(const char* str, int32_t bitStream = 0)
{
    return (*str == STRING_END_CHAR) ? bitStream : computeBitStream(str + 1, (bitStream << EIGHT_BITS) | static_cast<int8_t>(*str));
}
