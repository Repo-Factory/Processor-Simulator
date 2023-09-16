#include "cpu.hpp"
#include "loader.hpp"
#include "memory.hpp"
#include <memory>

#ifndef ASSEMBLY_PATH
    #define ASSEMBLY_PATH ""
#endif

#define FOREVER 1

int main() {
    std::unique_ptr<Loader> loader = std::make_unique<Loader>();
    std::unique_ptr<MIPSCPU> cpu = std::make_unique<MIPSCPU>();
    loader->loadProgram(cpu->memory, ASSEMBLY_PATH);        // defined in CMakeLists.txt   
    while (FOREVER) 
        executeInstruction(*cpu);
    exit(EXIT_SUCCESS);
}
