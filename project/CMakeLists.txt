cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c constants.h main.h huffman.c huffman.h input.c input.h)
add_executable(project ${SOURCE_FILES})