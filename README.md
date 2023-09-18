Conner Sommerfield
Red Id: 824769654

Directories

accumulator/                        Code for simulator using an accumulator base machine
    include/
        cpu.hpp                     Declares MIPSCPU class with functions for instruction emulation and register declarations.
        loader.hpp                  Declares Loader class with functions to place instructions into memory
        memory.hpp                  Declares memory struct which lays out sections of memory as well as declaring read/write functions
    src/
        cpu.cpp                     Defines switch statement laid out in assignment with corresponding instruction logic
        loader.cpp                  Iterates through assembly file and places instructions into cpu memory field 
        memory.cpp                  Simply implements read and write procedures
        main.cpp                    Main program will load instructions to memory, then run an infinite loop reading instructions
    CMakeLists.txt                  Build File which will generate make file to compile project
    package.xml                     File to work with my preferred build/package manager for C++ (colcon/ROS2)

binary_encodings/
    binary_encodings.cpp            It's a cpp file but it actually just holds text explaining the binary encodings for Part 3
    quadratic_accumulator_hex.s     Pure hex file in format laid out in binary_encodings.cpp, read cpp file first to understand this
    quadratic_stack_hex.s           Again, another hex file for other machine, read the cpp file for more details and explanation

helpers/                            Code shared between stack and accumulator for various general functions
    bit_operations                  Contains some bit manipulation functions to work with bitstreams (I didn't want to use raw strings)
    debug_helpers                   Contains printing functions to visualize memory and other aspects of program
    file_handling_helpers           Keeps file handling operations out of main code (like opening files, error checking, etc)

stack/                              Code for simulator using a stack based machine
    include/
        cpu.hpp                     Declares MIPSCPU class with functions for instruction emulation and register declarations.
        loader.hpp                  Declares Loader class with functions to place instructions into memory
        memory.hpp                  Declares memory struct which lays out sections of memory as well as declaring read/write functions
    src/
        cpu.cpp                     Defines switch statement laid out in assignment with corresponding instruction logic
        loader.cpp                  Iterates through assembly file and places instructions into cpu memory field 
        memory.cpp                  Simply implements read and write procedures
        main.cpp                    Main program will load instructions to memory, then run an infinite loop reading instructions
    CMakeLists.txt                  Build File which will generate make file to compile project
    package.xml                     File to work with my preferred build/package manager for C++ (colcon/ROS2)

quadratic_eval.s                    Original assembly code given with corrections and comments
quadratic_accumulator.s             Assembly code rewritten in syntax understood by accumulator simulator
quadratic_stack.s                   Assembly code rewritten in syntax understood by stack simulator