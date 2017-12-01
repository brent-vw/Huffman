//
// Created by Brent Van Wynsberge on 1/12/17.
//
#include "twopass.h"
#include "../datastructures/structs.h"

int fixWeight(huff_node *pNode);

void two_pass_decode(){
    input* in = allocate_input();
    //Lees hoeveel nodes er zijn
    int size;
    fread(&size, sizeof(int), 1, stdin);
    char chars[size];
    int sizes[size];

    //Lees de nodes
    for (int j = 0; j < size; ++j) {
        char ch;
        fread(&ch, sizeof(char), 1, stdin);
        chars[j] = ch;
    }

    //Lees de gewichten van de nodes
    for (int j = 0; j < size; ++j) {
        int rd;
        fread(&rd, sizeof(int), 1, stdin);
        sizes[j] = rd;
    }

    //Bouw de nodes op
    node* currentNode = in->nodes;
    for (int j = 0; j < size; ++j) {
        if(!currentNode){
            in->nodes = allocate_node(chars[j], in);
            currentNode = in->nodes;
            currentNode->weight = sizes[j];
        } else {
            currentNode->next = allocate_node(chars[j], in);
            currentNode = currentNode->next;
            currentNode->weight = sizes[j];
        }
    }

    size_t max_size =  1 << (sizeof(unsigned char)*8);

    /*
     * Bouw de stapel op dezelfde manier op als eerder zodat dezelfde huffman boom ontstaat
     */

    //Allocate enough for all leaves, perfect binary tree with n leaves has 2n-1 elements
    size_t stack_size = 2*in->nodes_size-1;
    stack* ptr = allocate_stack(stack_size);
    stack *tmp = allocate_stack(stack_size);

    //Add al nodes to the stack
    int maxCode = build_stack(in, ptr);

    //build the huffman tree
    order_node* nng_node = NULL;
    order_node* current = NULL;
    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    while(ptr->top > 0){
        huff_node* node1 = pop(ptr);
        huff_node* node2 = pop(ptr);
        huff_node* new_node = create_node(node1, node2);
        if(!current){
            nng_node = allocate_order_node(node1);
            nng_node->next = allocate_order_node(node2);

            if(!node2->left){
                order_nodes[(unsigned char) node2->value] = nng_node->next;
            }

            current = nng_node->next;
        } else {
            current->next = allocate_order_node(node1);
            current = current->next;
            if(!node1->left){
                order_nodes[(unsigned char) node1->value] = current;
            }

            current->next = allocate_order_node(node2);
            current = current->next;
            if(!node2->left){
                order_nodes[(unsigned char) node2->value] = current;
            }
        }

        while(peek(ptr) && peek(ptr)->weight < new_node->weight){
            push(tmp, pop(ptr));
        }
        push(ptr, new_node);
        pushAll(ptr, tmp);

    }

    FILE* fout = stdout;

    huff_node* root = pop(ptr);
    if(current) {
        current->next = allocate_order_node(root);
    }
    fixRefs(root, NULL);
    makeDepth(root);

    char* text = calloc(9, sizeof(char));
    size_t t_size;
    char c;
    int count = 0;
    huff_node* h_current = root;
    //Lees de codes
    while ((t_size = fread(&c, sizeof(char), 1, stdin))) {

        if (t_size < 1) {
            break;
        }

        //Lees het bitpatroon van de byte
        sprintf(text, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));

        for (int i = 0; i < 8; ++i) {
            count++;
            char bit = text[i];
            if(bit=='1'){
                h_current = h_current->left;
            } else {
                h_current = h_current->right;
            }

            //Blad bereikt
            if(!h_current->left){
                //Het character in het blad
                char newChar = h_current->value;
                fwrite(&newChar, sizeof(char), 1, fout);

                //Dit is de laatste iteratie, nadien blijven er geen gewichten meer over
                if(h_current->weight==1&&!nng_node->node->parent->parent){
                    break;
                }

                //Pas de frequentie aan
                downgrade(find_node(nng_node, root), order_nodes[(unsigned char) newChar]->node, order_nodes, nng_node);
                h_current = root;
            }
        }
    }

    //geef de resources weer vrij
    free_stack(tmp);
    free_stack(ptr);
    free_input(in);
}

/**
 * Pas de gewichten van de nodes die geen bladeren zijn aan. Deze worden namelijk niet meegegeven.
 * @param pNode de wortel
 * @return het gewicht van de huidige wortel
 */
int fixWeight(huff_node *pNode) {
    if(!pNode->left){
        return pNode->weight;
    }
    pNode->weight = fixWeight(pNode->left) + fixWeight(pNode->right);
    return pNode->weight;
}