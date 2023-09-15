#include "cpu.hpp"
#include "loader.hpp"
#include "memory.hpp"

int main() {
    Memory memory;
    load(memory, ASSEMBLY_PATH);
    return 0;
}



