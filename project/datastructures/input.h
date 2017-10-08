//
// Created by Brent Van Wynsberge on 4/10/17.
//

#ifndef PROJECT_INPUT_H
#define PROJECT_INPUT_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "structs.h"
#include "../constants.h"

input* read_input();
input* allocate_input();
void free_input(input*);

void flush_buffer(input*, int, int*);

void increment_node(int, input*);
node* allocate_node(int, input*);
void free_nodes(node*);
void move_node(node*);
void reverse_nodes(input*);

#endif //PROJECT_INPUT_H
