//
// Created by Brent Van Wynsberge on 4/10/17.
//

#ifndef PROJECT_INPUT_H
#define PROJECT_INPUT_H

#include "main.h"

typedef struct node node;

struct node{
    int value;
    int weight;
    node* next;
};

typedef struct {
    size_t size;
    int* content;
    node* nodes;
} input;

input* read_input();
input* allocate_input();
void free_input(input* in);

void flush_buffer(input* input, int counter, int* buffer);

node* increment_node(int c, node* root);
node* allocate_node(int c, node* previous);
void free_nodes(node* node);
void sort_list(node* nd);

#endif //PROJECT_INPUT_H
