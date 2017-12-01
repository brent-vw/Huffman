//
// Created by Brent Van Wynsberge on 5/11/17.
//

#ifndef PROJECT_ADAPTIVE_H
#define PROJECT_ADAPTIVE_H

#include <stdlib.h>
#include "../datastructures/huff_node.h"
#include "../datastructures/bit_operations.h"
#include "../datastructures/order_list.h"
#define NNG -1;
void adaptive_encode();
void adaptive_decode();

bool check_nodes(order_node*);
bool check_tree(huff_node*);

void write_new(char*, size_t* written, huff_node* nng, char c, FILE* fout);
void write_code(char *buffer, size_t *written, huff_node *code, FILE *fout);
void write_bit(char* buffer, size_t* written, char bit, FILE* fout);

void update(order_node* node, order_node** nodes, order_node* nng);
void nng(char c, order_node* nng, order_node** nodes, int index);

void update_tree(huff_node** oldTree, huff_node* leaf);
void swap(order_node* o_node1, order_node* o_node2, order_node** nodes);
order_node* find_node(order_node* nng, huff_node* node);
void makeDepth(huff_node* node);
#endif //PROJECT_ADAPTIVE_H
