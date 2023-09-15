cmake_minimum_required(VERSION 3.5)
project(stack)

get_filename_component(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
find_package(ament_cmake REQUIRED)
set(CMAKE_CXX_STANDARD 20)

# Add your package's source files
add_executable(
    stack 
    ${SRC_DIR}/stack/src/cpu.cpp
    ${SRC_DIR}/stack/src/loader.cpp
    ${SRC_DIR}/stack/src/memory.cpp
    ${SRC_DIR}/stack/src/main.cpp
)

target_include_directories(
    stack PUBLIC 
    ${SRC_DIR}/stack/include
)

add_definitions(-DASSEMBLY_PATH="${SRC_DIR}/quadratic_stack.s")

# Install the executable
install(TARGETS stack
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()