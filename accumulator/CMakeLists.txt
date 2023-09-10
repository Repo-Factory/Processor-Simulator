cmake_minimum_required(VERSION 3.5)
project(accumulator)

get_filename_component(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

# Add your package's source files
add_executable(
    accumulator 
    ${SRC_DIR}/accumulator/src/accumulator.cpp
    ${SRC_DIR}/accumulator/src/main.cpp
)

# Link gtest and other libraries to  executable
target_link_libraries(accumulator
  dependency_library
  ${rclcpp_LIBRARIES}
)

target_include_directories(
    accumulator PUBLIC 
    ${SRC_DIR}/accumulator/include
)

# Install the executable
install(TARGETS accumulator
  DESTINATION lib/${PROJECT_NAME}
)
