cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c constants.h main.h huffman/huffman.c huffman/huffman.h datastructures/input.c datastructures/input.h datastructures/stack.c datastructures/stack.h datastructures/structs.h datastructures/bit_operations.c datastructures/bit_operations.h)
add_executable(project ${SOURCE_FILES})