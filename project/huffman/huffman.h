//
// Created by Brent Van Wynsberge on 4/10/17.
//

#ifndef PROJECT_HUFFMAN_H
#define PROJECT_HUFFMAN_H
#include <ntsid.h>
#include <time.h>
#include "../datastructures/input.h"
#include "../datastructures/stack.h"
#include "../datastructures/bit_operations.h"

void huffman_encode();
void huffman_decode();

int build_stack(input*, stack*);

huff_node* create_node(huff_node* left, huff_node* right);
void free_tree(huff_node* tree);

#endif //PROJECT_HUFFMAN_H
