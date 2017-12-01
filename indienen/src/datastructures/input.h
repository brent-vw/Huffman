//
// Created by Brent Van Wynsberge on 4/10/17.
//

#ifndef PROJECT_INPUT_H
#define PROJECT_INPUT_H

#include "structs.h"

input *read_input(bool);
input* allocate_input();
void free_input(input*);

void flush_buffer(input*, size_t , const char*, bool);

void increment_node(char , input*);
node* allocate_node(char, input*);
node* _allocate_node(char);
void free_nodes(node*);
void move_node(node*);
void reverse_nodes(input*);

#endif //PROJECT_INPUT_H
