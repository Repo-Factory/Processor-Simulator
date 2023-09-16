#include "cpu.hpp"
#include "loader.hpp"
#include "memory.hpp"
#include <memory>

int main() {
    Memory memory;
    std::unique_ptr<Loader> loader = std::make_unique<Loader>();
    loader->loadProgram(memory, ASSEMBLY_PATH);        // defined in CMakeLists.txt
    return 0;
}
