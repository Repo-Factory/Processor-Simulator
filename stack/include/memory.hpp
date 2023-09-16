#pragma once
#include <stdint.h>
#include <map>
#include <string>

#define USER_TEXT_SIZE 128
#define KERNEL_TEXT_SIZE  64
#define USER_DATA_SIZE 128
#define STACK_SIZE 128
#define KERNEL_DATA_SIZE 64

struct Memory 
{
    int32_t userText[USER_TEXT_SIZE] = {0};
    int32_t kernelText[KERNEL_TEXT_SIZE] = {0};
    int32_t userData[USER_DATA_SIZE] = {0};
    int32_t stack[STACK_SIZE] = {0};
    int32_t kernelData[KERNEL_DATA_SIZE] = {0};
    int32_t* userTextPtr = userText;
    int32_t* kernelDataPtr = kernelData;
    int32_t* kernelTextPtr = kernelText;
    int32_t* stackPtr = stack;
    int32_t* userDataPtr = userData;
    std::map<int32_t, int32_t*> symbol_table;
};

int32_t readContents(int32_t* address);
void writeContents(int32_t* address, int32_t data);