//
// Created by Brent Van Wynsberge on 1/12/17.
//
#include "block.h"
#include "../main.h"

/**
 * encodeer het huidige blok
 * @param fp pointer naar het uitvoerbestand
 * @return true als er nog een blok volgt
 */
bool encode_block(FILE* fp){
    //defaults
    size_t max_size =  1 << (sizeof(unsigned char)*8);
    size_t block_size = BLOCK_SIZE;

    //init boom
    huff_node* tree = new_node();
    tree->value = NNG;
    tree->weight = 0;
    order_node* nng_node = allocate_order_node(tree);

    //init buffer
    size_t buffer_written = 0;
    char buffer[9];
    memset(buffer, '\0', 9);

    //init dictionary
    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    //lees
    char c;
    int i =0;
    size_t size;
    bool more = false;

    while ((size = fread(&c, sizeof(char), 1, stdin))){

        //niets meer te lezen
        if(size<1){
            break;
        }

        //dictionary index
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

        //pas het nodenummer binnen het blok aan
        i++;
        if(i==block_size){
            more = true;
            break;
        }
    }

    //schrijf nng uit om het laatste blok weg te schrijven
    if(more==false){
        write_code(buffer, &buffer_written, nng_node->node, fp);
    }

    //vul aan met 0 bits om mooi rond te maken
    while (buffer_written>0){
        write_bit(buffer, &buffer_written, '0', fp);
    }

    //ga naar wortel en geef alles vrij
    while (tree->parent){
        tree = tree->parent;
    }
    free_tree(tree);
    free_list(nng_node);
    return more;
}

void block_encode(){
    //file pointer voor debugging
    FILE* fp = stdout;

    while (encode_block(fp)){
    }

    //sluit het filex
    fclose(fp);
}