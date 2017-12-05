//
// Created by Brent Van Wynsberge on 29/11/17.
//
#include "sliding.h"

void sliding_encode(){
    size_t max_size =  1 << (sizeof(unsigned char)*8);
    //init boom
    huff_node* tree = new_node();
    tree->value = NNG;
    tree->weight = 0;
    order_node* nng_node = allocate_order_node(tree);

    size_t buffer_written = 0;
    char buffer[9];
    memset(buffer, '\0', 9);

    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    int window_size = WINDOW_SIZE;
    unsigned char* window = calloc((size_t) window_size, sizeof(unsigned char));
    int window_index = 0;

    //lees
    char c;
    int i =0;
    size_t size;
    while ((size = fread(&c, sizeof(char), 1, stdin))) {
        if (size < 1) {
            break;
        }

        unsigned char index = (unsigned char) c;

        //nng
        if(order_nodes[index]==NULL){
            //write nng and the node
            write_new(buffer, &buffer_written, nng_node->node, c, stdout);


            //make new node
            nng(c, nng_node, order_nodes, index);
        } else {

            //write code
            write_code(buffer, &buffer_written, order_nodes[index]->node, stdout);

            //update tree
            update(order_nodes[index], order_nodes, nng_node);
        }

        slide(&i, &window_index, window, order_nodes, index, nng_node, &tree);
    }

    //schrijf nng uit om het einde aan te geven
    write_code(buffer, &buffer_written, nng_node->node, stdout);

    //vul de f
    while (buffer_written>0){
        write_bit(buffer, &buffer_written, '0', stdout);
    }

    while (tree->parent){
        tree = tree->parent;
    }

    free_tree(tree);
    free(order_nodes);
    free_list(nng_node);
}
