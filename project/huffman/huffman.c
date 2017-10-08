//
// Created by Brent Van Wynsberge on 4/10/17.
//
#include "huffman.h"
#include "../datastructures/structs.h"

void print_tree(huff_node *node, int depth){
    if(!node){
        return;
    }

    char value = (char) (node->value == 0 ? 'X' : node->value);

    printf("%c(%d) - depth %i\n", value, node->weight, depth);

    print_tree(node->left, depth+1);
    print_tree(node->right, depth+1);

}

void _build_dictionary(code** dictionary, char* tree, huff_node* node, int length){
    if(!node->left||!node->right){
        code* encoding = malloc(sizeof(code));
        encoding->code = malloc(sizeof(char)*length+1);
        tree[length] = '\0';
        strcpy(encoding->code, tree);
        encoding->key = node->value;
        encoding->code_length = length;
        printf("Character: %c, Code: %s\n",(char) encoding->key, encoding->code);
        dictionary[encoding->key] = encoding;
    } else {
        tree[length] = '0';
        _build_dictionary(dictionary, tree, node->left, length+1);
        tree[length] = '1';
        _build_dictionary(dictionary, tree, node->right, length+1);
    }
}

code** build_dictionary(huff_node* root, int size){
    code** codes = malloc((size+1)* sizeof(code*));
    char tree[32];
    _build_dictionary(codes, tree, root, 0);
    return codes;
}

void huffman_encode(){
    clock_t start = clock();
    input* in = read_input();

    //Allocate enough for all leaves, perfect binary tree with n leaves has 2n-1 elements
    size_t stack_size = 2*in->nodes_size-1;
    stack* ptr = allocate_stack(stack_size);
    stack *tmp = allocate_stack(stack_size);

    //Add al nodes to the stack
    int maxCode = build_stack(in, ptr);

    //build the huffman tree
    while(ptr->top > 0){
        huff_node* node1 = pop(ptr);
        huff_node* node2 = pop(ptr);
        huff_node* new_node = create_node(node1, node2);

        while(peek(ptr) && peek(ptr)->weight < new_node->weight){
            push(tmp, pop(ptr));
        }
        push(ptr, new_node);
        pushAll(ptr, tmp);

    }

    huff_node* root = pop(ptr);
    code** codes = build_dictionary(root, maxCode);

    FILE* fp = fopen("/Users/brentvw/Projects/ugent/da3/project/out.txt", "wb");
    unsigned int buffer=0;
    //write the tree

    //write the characters

    //write the encoded file
    buffer = 0;
    int bits_written = 0;
    size_t max_bits = 32;
    for (int i = 0; i < in->size; ++i) {
        code* current = codes[in->content[i]];
        for (int j = 0; j < current->code_length; ++j) {
            char c = current->code[j];
            if(c=='1'){
               buffer = set_bit(buffer, bits_written++);
            } else {
                buffer = clear_bit(buffer, bits_written++);
            }
            if(bits_written>=max_bits){
                fwrite(&buffer, sizeof(int),1, fp);
                buffer = 0;
                bits_written = 0;
            }
        }
    }
    if(bits_written>0){
        fwrite(&buffer, sizeof(int),1, fp);
    }

    free_stack(tmp);
    free_stack(ptr);
    free_input(in);
    for (int i = 0; i < maxCode; ++i) {
        if(codes[i])
            free(codes[i]);
    }
    free(codes);

    clock_t end = clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed %.*f\n", 5, seconds);
    printf("Biggest code: %i\n", maxCode);
}

void huffman_decode(){

}

int build_stack(input* in, stack* stack){
    reverse_nodes(in);
    node* current = in->nodes;
    int max = -1;

    while(current){
        huff_node* node = malloc(sizeof(*node));
        node->left = NULL;
        node->right = NULL;
        node->value = current->value;
        node->weight = current->weight;

        push(stack, node);
        max = node->value > max ? node->value : max;

        current = current->next;
    }
    return max;
}

huff_node* create_node(huff_node* left, huff_node* right){
    huff_node* node = malloc(sizeof(*node));
    node->left = left;
    node->right = right;
    int weight = 0;
    if(left){
        weight += left->weight;
    }
    if(right){
        weight += right->weight;
    }
    node->weight = weight;
    node->value = -1;
    return node;
}

void free_tree(huff_node* tree){
    if(!tree){
        return;
    }
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}
