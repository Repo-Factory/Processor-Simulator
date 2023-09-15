#include "cpu.hpp"
#include "loader.hpp"
#include "memory.hpp"

int main() {
    Memory memory;
    load(memory, ASSEMBLY_PATH);
    return 0;
}


/* for (int i = 0; (void*)&i < (void*)&memory + 1024; ++i) {
        std::cout << "Memory[" << i << "]: " << std::hex << &memory + i << std::dec << std::endl;
    }
 */