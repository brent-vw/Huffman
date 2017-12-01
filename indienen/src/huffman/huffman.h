//
// Created by Brent Van Wynsberge on 4/10/17.
//

#ifndef PROJECT_HUFFMAN_H
#define PROJECT_HUFFMAN_H
#include <time.h>
#include <stdlib.h>
#include "../datastructures/input.h"
#include "../datastructures/stack.h"
#include "../datastructures/bit_operations.h"
#include "../datastructures/huff_node.h"

void huffman_encode();
void huffman_decode();

code** build_dictionary(huff_node* root, int size);
int print_tree(huff_node *node, char* buffer, char* characters, int index, int* weights);
huff_node *rebuild_tree(char tree[], int tree_size, node *chars);
#endif //PROJECT_HUFFMAN_H
