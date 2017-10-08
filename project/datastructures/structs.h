//
// Created by Brent Van Wynsberge on 7/10/17.
//

#ifndef PROJECT_STRUCTS_H
#define PROJECT_STRUCTS_H
typedef struct huff_node huff_node;
struct huff_node{
    int weight;
    int value;
    huff_node *left, *right;
};

typedef struct stack stack;
struct stack{
    huff_node** stack;
    size_t capacity;
    int top;
};

typedef struct code code;
struct code{
    int key;
    char* code;
    int code_length;
};

typedef struct node node;
struct node{
    int value;
    int weight;
    node* next;
};

typedef struct {
    size_t size;
    int* content;
    size_t nodes_size;
    node* nodes;
} input;

#endif //PROJECT_STRUCTS_H
