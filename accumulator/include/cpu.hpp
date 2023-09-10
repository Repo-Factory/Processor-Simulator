#define NUM_REGISTERS 32
#define MEMORY_SIZE 1024

void push() 
{

}

void pop() 
{

}

void add() 
{

}

void mult() 
{

}

void end() 
{

}
 
// MIPS instruction structure
struct MIPSInstruction {
    char* opcode;
    int rs;
    int rt;
    int rd;
    int immediate;
};

// MIPS CPU structure
struct CPUMIPS {
    int registers[NUM_REGISTERS];
    int memory[MEMORY_SIZE];
    int pc;     // Program counter
    int IF_ID; // Instruction fetched in IF stage
    MIPSInstruction ID_EX; // Instruction decoded in ID stage
    int EX_MEM; // Execution result in EX stage
    int MEM_WB; // Memory access result in MEM stage
};

constexpr unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + (*str++);
    }
    return hash;
}

void executeInstruction(MIPSInstruction& instruction, CPUMIPS& cpu) {
    switch (hash(instruction.opcode)) {
        case hash("PUSH"):
            push();
            break;
        case hash("POP"):
            pop();
            break;
        case hash("ADD"):
            add();
            break;
        case hash("MULT"):
            mult();
            break;
        case hash("END"):
            end();
            break;
        default:
            cpu.pc++;
            break;
    }
}
