//
// Created by Brent Van Wynsberge on 7/10/17.
//
#include "stack.h"

stack *allocate_stack(size_t capacity) {
    stack *ptr = malloc(sizeof(stack));
    ptr->capacity = capacity;
    ptr->top = -1;
    huff_node** stack = malloc(sizeof(huff_node*)*capacity);
    for (int i = 0; i < capacity; ++i) {
        stack[i] = NULL;
    }
    ptr->stack = stack;
    return ptr;
}

bool isEmpty(stack* stack){
    return stack->top < 0;
}

bool isFull(stack* stack){
    return stack->top >= (int) stack->capacity;
}

void free_stack(stack *stack) {
    free(stack->stack);
    free(stack);
}

void push(stack *stack, huff_node *node) {
    //Increment the top location and add to the stack if it's not full
    if(!isFull(stack)){
        stack->stack[++stack->top] = node;
    } else {
        fprintf(stderr, "Stack is full; size: %i, head: %i\n", (int) stack->capacity, stack->top);
    }
}

void pushAll(stack *ptr, stack *data){
    while(!isEmpty(data)){
        push(ptr, pop(data));
    }
}

huff_node *peek(stack *stack) {
    //peek if the stack is not empty
    if(!isEmpty(stack)){
        return stack->stack[stack->top];
    }
    return NULL;
}

huff_node *pop(stack *stack) {
    //Get from the stack en decrement the top location
    if(!isEmpty(stack)){
        huff_node* value = stack->stack[stack->top--];
        return value;
    }
    return NULL;
}
