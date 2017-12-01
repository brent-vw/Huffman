#include "twopass.h"
#include "../datastructures/structs.h"

/**
 * Pas de referenties naar de ouders aan om in twee richtingen te kunenn traversen
 * @param node
 * @param parent
 */
void fixRefs(huff_node* node, huff_node* parent){
    if(node){
        node->parent = parent;
        fixRefs(node->left, node);
        fixRefs(node->right, node);
    }
}

void two_pass_encode(){
    input* in = read_input(true);
    if(in->size==0){
        exit(0);
    }

    //voeg de nng node toe om verwijderen mogelijk te maken
    char nng_c = (char) NNG;
    node* nng = allocate_node(nng_c, in);
    nng->weight = 0;
    nng->next = in->nodes;
    in->nodes = nng;

    size_t max_size =  1 << (sizeof(unsigned char)*8);

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

    //wijzig de stapel tot 2 nodes van het juiste gewicht samen gevoegd kunnen worden, herhaal tot de stapel enkel de wortel bevat
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

    //de wortel van de boom
    huff_node* root = pop(ptr);
    if(current) {
        current->next = allocate_order_node(root);
    }
    fixRefs(root, NULL);
    makeDepth(root);

    free_stack(tmp);
    free_stack(ptr);


    FILE* fp = stdout;

    //init alle codes
    char tree_coded[stack_size+1], characters[stack_size+1];
    int weights[stack_size+1];
    memset(tree_coded, '\0', stack_size+1);
    memset(characters, '\0', stack_size+1);
    memset(weights, 0, stack_size+1);

    //build the tree in the correct output format
    int depth = print_tree(root, tree_coded, characters, 0, weights);
    tree_coded[depth] = '\0';

    //write the tree
    size_t bits_written = 0;
    size_t max_bits = 8;
    char buff[max_bits+1];
    memset(buff, '\0', max_bits+1);

    // put amount of nodes
    reverse_nodes(in);
    node* curr = in->nodes;
    int x = 0;
    while (curr){
        x++;
        curr = curr->next;
    }
    fwrite(&x, 1, sizeof(int), fp);

    //write the characters in the order they appear in the encoded tree
    curr = in->nodes;
    while (curr){
        fwrite(&curr->value, sizeof(char), 1, fp);
        curr = curr->next;
    }

    //write the frequencies in the order they appear in the encoded tree
    curr = in->nodes;
    while (curr){
        fwrite(&curr->weight, sizeof(int), 1, fp);
        curr = curr->next;
    }

    //write the data
    for(int i =0; i<in->size; i++){
        char c = in->content[i];
        unsigned char index = (unsigned char) c;
        //write code
        write_code(buff, &bits_written, order_nodes[index]->node, fp);

        //update tree
        if(i<in->size-1) {
            downgrade(find_node(nng_node, root), order_nodes[index]->node, order_nodes, nng_node);
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

    //free al resources
    free_input(in);
    free_tree(root);
    free_list(nng_node);
    free(order_nodes);
}