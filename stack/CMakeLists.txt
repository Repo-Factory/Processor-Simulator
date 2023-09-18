cmake_minimum_required(VERSION 3.5)
project(stack)

get_filename_component(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
find_package(ament_cmake REQUIRED)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
if (NOT TARGET helpers)
    add_subdirectory(${SRC_DIR}/helpers ${CMAKE_BINARY_DIR}/helpers-build)
endif()

# Add package's source files
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

# Link to helpers code
target_link_libraries(stack
  helpers
)

# Install the executable
install(TARGETS stack
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
