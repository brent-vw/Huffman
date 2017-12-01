//
// Created by Brent Van Wynsberge on 5/11/17.
//

#ifndef PROJECT_HUFF_NODE_H
#define PROJECT_HUFF_NODE_H

#include "structs.h"
huff_node* new_node();
huff_node* create_node(huff_node* left, huff_node* right);
void free_tree(huff_node* tree);
#endif //PROJECT_HUFF_NODE_H
