//
// Created by Brent Van Wynsberge on 1/12/17.
//

#ifndef PROJECT_TWOPASS_H
#define PROJECT_TWOPASS_H

#include "../huffman/huffman.h"
#include "../main.h"

void two_pass_encode();
void two_pass_decode();

void fixRefs(huff_node* node, huff_node* parent);
#endif //PROJECT_TWOPASS_H
