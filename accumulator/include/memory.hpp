#include <stdint.h>

#define USER_TEXT_SIZE 128
#define KERNEL_TEXT_SIZE  128
#define USER_DATA_SIZE 128
#define STACK_SIZE 128
#define KERNEL_DATA_SIZE 128
#define SUCCESS 1

struct memory {
    int32_t userText[USER_TEXT_SIZE];
    int32_t kernelText[KERNEL_TEXT_SIZE];
    int32_t userData[USER_DATA_SIZE];
    int32_t stack[STACK_SIZE];
    int32_t kernelData[KERNEL_DATA_SIZE];
};

int32_t getContents(int32_t* memory, int32_t address)
{
    return *(memory + address);
}

int32_t writeContents(memory& memory, int32_t address, int32_t data)
{
    memory.userData[address] = data;
    return SUCCESS;
}