#pragma once
#include <stdint.h>
#include <string>

#define INIT_BIT_STREAM 0
#define STRING_END_CHAR '\0'
#define EIGHT_BITS 8
#define NEXT_LETTER(word) (word + 1)

int32_t labelToBitStream(const std::string& word);
int32_t stringToBitStream(const std::string& word);

// constexpr must be defined in header
constexpr int32_t computeBitStream(const char* word, int32_t bitStream = 0)
{
    return *word == STRING_END_CHAR ? bitStream : computeBitStream(NEXT_LETTER(word), (bitStream << EIGHT_BITS) | static_cast<int8_t>(*word));
}   // This function uses recursive method to compute bit stream at compile time
