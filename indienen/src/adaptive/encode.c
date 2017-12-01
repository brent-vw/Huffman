//
// Created by Brent Van Wynsberge on 29/11/17.
//
#include "adaptive.h"

void adaptive_encode(){
    FILE* fp = stdout;
    size_t max_size =  1 << (sizeof(unsigned char)*8);

    //init boom
    huff_node* tree = new_node();
    tree->value = NNG;
    tree->weight = 0;
    order_node* nng_node = allocate_order_node(tree);

    //maak de buffer klaar
    size_t buffer_written = 0;
    char buffer[9];
    memset(buffer, '\0', 9);

    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    //Elke character
    char c;
    int i =0;
    size_t size;
    while ((size = fread(&c, sizeof(char), 1, stdin))){
        if(size<1){
            break;
        }
        i++;
        int index = (unsigned char) c;

        //nng
        if(order_nodes[index]==NULL){
            //write nng and the node
            write_new(buffer, &buffer_written, nng_node->node, c, fp);

            //make new node
            nng(c, nng_node, order_nodes, index);
        } else {
            //write code
            write_code(buffer, &buffer_written, order_nodes[index]->node, fp);

            //update tree
            update(order_nodes[index], order_nodes, nng_node);
        }
    }

    //schrijf nng om af te sluiten
    write_code(buffer, &buffer_written, nng_node->node, fp);

    //vul de laatste byte
    while (buffer_written>0){
        write_bit(buffer, &buffer_written, '0', fp);
    }

    //free memory
    while (tree->parent){
        tree = tree->parent;
    }

    free_tree(tree);
    free_list(nng_node);
}