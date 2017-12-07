//
// Created by Brent Van Wynsberge on 4/10/17.
//
#include "huffman.h"
#include "../datastructures/order_list.h"

/**
 * Build te encoded version of the tree
 * @param node current node
 * @param buffer buffer containing tree index
 * @param characters list of all characters
 * @param index current index
 * @param weights list of weights
 * @return length of tree/index
 */
int print_tree(huff_node *node, char* buffer, char* characters, int index, int* weights){
    if(!node->right&&!node->left){
        characters[index] = node->value;
        if(weights){
            weights[index] = node->weight;
        }
        buffer[index++] = '1';
        return index;
    } else {
        characters[index] = '\0';
        buffer[index++] = '0';
        index = print_tree(node->left, buffer, characters, index, weights);
        return print_tree(node->right, buffer, characters, index, weights);
    }
}

void _build_dictionary(code** dictionary, char* tree, huff_node* node, int length){
    if(node->left==NULL||node->right==NULL){
        code* encoding = malloc(sizeof(*encoding));
        encoding->code = malloc(sizeof(char)*length+1);
        tree[length] = '\0';
        strcpy(encoding->code, tree);
        encoding->key = node->value;
        encoding->code_length = length;

        dictionary[(unsigned char)encoding->key] = encoding;
    } else {
        tree[length] = '0';
        _build_dictionary(dictionary, tree, node->left, length+1);
        tree[length] = '1';
        _build_dictionary(dictionary, tree, node->right, length+1);
    }
}

code** build_dictionary(huff_node* root, int size){
    code** codes = calloc((size_t) size + 1, sizeof(code*));
    char* tree = malloc((size+1)*sizeof(char));
    memset(tree, '\0', size+1);
    _build_dictionary(codes, tree, root, 0);
    return codes;
}

void huffman_encode(){
    input* in = read_input(true);
    if(in->size==0){
        exit(0);
    }
    //Allocate enough for all leaves, perfect binary tree with n leaves has 2n-1 elements
    size_t stack_size = 2*in->nodes_size-1;
    stack* ptr = allocate_stack(stack_size);
    stack *tmp = allocate_stack(stack_size);

    //Add al nodes to the stack
    int maxCode = build_stack(in, ptr);

    //build the huffman tree
    huff_node* watch;
    while(ptr->top > 0){
        huff_node* node1 = pop(ptr);
        huff_node* node2 = pop(ptr);
        huff_node* new_node = create_node(node1, node2);
        if(node1->value=='1'){
            watch = node1;
        } else if(node2->value=='1'){
            watch = node2;
        }
        while(peek(ptr) && peek(ptr)->weight < new_node->weight){
            push(tmp, pop(ptr));
        }
        push(ptr, new_node);
        pushAll(ptr, tmp);

    }

    huff_node* root = pop(ptr);
    code** codes = build_dictionary(root, maxCode);

    FILE* fp = stdout;

    char tree_coded[stack_size+1], characters[stack_size+1];
    memset(tree_coded, '\0', stack_size+1);
    memset(characters, '\0', stack_size+1);

    //build the tree in the correct output format
    int depth = print_tree(root, tree_coded, characters, 0, NULL);
    tree_coded[depth] = '\0';

    //write the amount of bytes the tree will take
    int amount_bits = (int)strlen(tree_coded);
    int amount_bytes = (amount_bits+8-1)/8;
    fputc((unsigned char) amount_bytes, fp);


    //write the tree
    int bits_written = 0;
    size_t max_bits = 8;
    char buff[max_bits+1];
    memset(buff, '\0', max_bits+1);

    for (int i = 0; i < amount_bits; ++i) {
        buff[bits_written++] = tree_coded[i];
        if(bits_written>=max_bits){
            unsigned char out = (unsigned char) strtoul(buff, NULL, 2);
            fwrite(&out, sizeof(unsigned char),1, fp);
            bits_written = 0;
        }
    }

    if(bits_written>0){
        for (int i = bits_written; i < max_bits; ++i) {
            buff[i] = '0';
        }
        char out = (unsigned char) strtoul(buff, NULL, 2);
        fwrite(&out, sizeof(unsigned char),1, fp);
    }

    //write the characters in the order they appear in the encoded tree
    for (int k = 0; k < depth; ++k) {
        if(tree_coded[k]=='1'){
            fwrite(&characters[k], sizeof(char), 1, fp);
        }
    }

    //write the encoded file
    memset(buff, '\0', max_bits);
    bits_written = 0;
    for (int i = 0; i < in->size; ++i) {
        code* current = codes[(unsigned char)in->content[i]];
        for (int j = 0; j < current->code_length; ++j) {
            char c = current->code[j];
            buff[bits_written++] = c;
            if(bits_written>=max_bits){
                unsigned char out = (unsigned char) strtoul(buff, NULL, 2);
                fwrite(&out, sizeof(unsigned char),1, fp);
                bits_written = 0;
                memset(buff, '\0', max_bits);
            }
        }
    }

    //write the last byte
    int zeros = 0;
    if(bits_written>0){
        zeros = (int) (max_bits - bits_written);
        for (int i = bits_written; i < max_bits; ++i) {
            buff[i] = '0';
        }
        unsigned char out = (unsigned char) strtoul(buff, (char **) (&buff + 8), 2);
        fwrite(&out, sizeof(unsigned char),1, fp);
    }

    //write how many bits of the last byte we should ignore
    unsigned char n = (unsigned char) (char) zeros;
    fwrite(&n, sizeof(unsigned char), 1, fp);

    //free al resources
    free_stack(tmp);
    free_stack(ptr);
    free_input(in);
    for (int i = 0; i < maxCode; ++i) {
        if(codes[i])
            free(codes[i]);
    }
    free(codes);
}



huff_node *rebuild_tree(char tree[], int tree_size, node *chars) {
    huff_node* root = new_node();
    root->left = new_node();
    root->left->parent = root;
    huff_node* current = root->left;
    node* current_char = chars;
    for (int i = 1; i < tree_size; ++i) {
        if(tree[i]=='0'){
            if(current->left==NULL){
                current->left = new_node();
                current->left->parent = current;
                current = current->left;
            } else if(current->right==NULL){
                current->right = new_node();
                current->right->parent = current;
                current = current->right;
            } else {
                while (current->right){
                    current = current->parent;
                }
                current->right = new_node();
                current->right->parent = current;
                current = current->right;
            }
        } else {
            current->value = current_char->value;
            current->weight = current_char->weight;

            current_char = current_char->next;
            current = current->parent;
            while (current->parent&&current->right){
                current = current->parent;
            }
            if(!(!current->parent&&current->right)) {
                current->right = new_node();
                current->right->parent = current;
                current = current->right;
            }
        }
    }
    return root;
}

void huffman_decode(){
    input* in = read_input(false);
    int i = 0;

    //read tree length
    char tree_length = in->content[i++];
    int tree_length_bits = tree_length*8;

    //read tree
    char tree[tree_length_bits+1];
    memset(tree, '\0', (tree_length*8)+1);
    for (int j=0; j < tree_length; ++j) {
        sprintf(tree+8*j, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(in->content[i]));
        i++;
    }

    while (tree[tree_length_bits]!='1'){
        tree[tree_length_bits] = '\0';
        tree_length_bits--;
    }
    tree_length_bits++;

    //count the characters
    int amount_chars = 0;

    for (int j = 0; j < tree_length_bits; ++j) {
        if(tree[j]=='1'){
            amount_chars++;
        }
    }

    //read the characters
    in->nodes = allocate_node(in->content[i++], in);
    node* current = in->nodes;
    for(int j=1; j<amount_chars; ++j){
        current->next = allocate_node(in->content[i++], in);
        current = current->next;
    }

    huff_node* huff_tree = rebuild_tree(tree, tree_length_bits, in->nodes);
    FILE* fp = stdout;

    char* text = calloc(9, sizeof(char));
    int j = 0;
    while (i < in->size - 1){
        unsigned char c = (unsigned char) in->content[i++];
        sprintf(text+j*8, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));
        j++;
        text = realloc(text, j*8*sizeof(char*));
    }

    int size = j*8;

    unsigned char ignore_bits = (unsigned char) in->content[i++];


    huff_node* current_node = huff_tree;
    for(j=0;j<=size-ignore_bits;j++){
        char c = text[j];

        if(current_node->left==NULL){
            fputc(current_node->value, fp);
            current_node = huff_tree;
        }

        if(c=='1'){
            current_node = current_node->right;
        } else {
            current_node = current_node->left;
        }
    }
    free_input(in);
    free_tree(huff_tree);
    free(text);
}


