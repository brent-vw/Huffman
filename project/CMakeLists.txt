cmake_minimum_required(VERSION 3.8)
project(project)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c constants.h main.h huffman/huffman.c huffman/huffman.h datastructures/input.c datastructures/input.h datastructures/stack.c datastructures/stack.h datastructures/structs.h datastructures/bit_operations.h adaptive/adaptive.c adaptive/adaptive.h datastructures/huff_node.c datastructures/huff_node.h datastructures/order_list.c datastructures/order_list.h sliding/sliding.c sliding/sliding.h adaptive/encode.c adaptive/decode.c sliding/encode.c sliding/decode.c twopass/twopass.c twopass/twopass.h twopass/encode.c twopass/decode.c block/block.c block/block.h block/encode.c block/decode.c)
add_executable(project ${SOURCE_FILES})