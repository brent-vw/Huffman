//
// Created by Brent Van Wynsberge on 7/10/17.
//

#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H

#include "structs.h"
#include "input.h"

stack* allocate_stack(size_t);
void free_stack(stack*);

void push(stack*, huff_node*);
void pushAll(stack*, stack*);
huff_node* peek(stack*);
huff_node* pop(stack*);

bool isEmpty(stack*);
bool isFull(stack*);

int build_stack(input* in, stack* stack);

#endif //PROJECT_STACK_H
