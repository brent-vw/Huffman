//
// Created by Brent Van Wynsberge on 29/11/17.
//
#include "sliding.h"

void sliding_decode(){
    FILE* fp = stdin;
    FILE* fout = stdout;

    size_t max_size =  1 << (sizeof(unsigned char)*8);
    //init boom
    huff_node* tree = new_node();
    tree->value = NNG;
    tree->weight = 0;
    order_node* nng_node = allocate_order_node(tree);


    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    //lees
    char* text = calloc(9, sizeof(char));

    bool nng_read = false;
    char* nextChar = calloc(9, sizeof(char));
    size_t bits_read = 0;

    huff_node* current = tree;

    int window_size = WINDOW_SIZE;
    unsigned char* window = calloc((size_t) window_size, sizeof(unsigned char));
    int window_index = 0;

    size_t size;
    char c;
    int count = 0;
    while ((size = fread(&c, sizeof(char), 1, fp))){

        if(size<1){
            break;
        }

        //zet de byte om naar zijn bitpatroon
        sprintf(text, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));

        for (int i = 0; i < 8; ++i) {
            //huidige bit
            char bit = text[i];

            //nng?
            if(!nng_read&&current==nng_node->node){
                nng_read = true;
            }

            //nng lees de bits in een char
            if(nng_read){
                //hou de bits bij
                nextChar[bits_read++] = bit;
                if(bits_read==8){
                    //gedaan met lezen
                    nng_read = false;
                    nextChar[bits_read] = '\0';

                    //schrijf weg
                    char newChar = (char) strtol(nextChar, 0, 2);
                    memset(nextChar, '\0', 9);
                    bits_read = 0;

                    //schrijf het character uit
                    fwrite(&newChar, sizeof(char), 1, fout);

                    //update de boom
                    nng(newChar, nng_node, order_nodes, (unsigned char) newChar);
                    update_tree(&tree, nng_node->node);

                    //verschuif het window
                    slide(&count, &window_index, window, order_nodes, (unsigned char) newChar, nng_node, &tree);
                    current = tree;
                }
                continue;
            }

            //overloop de boom
            if(bit=='1'){
                current = current->left;
            } else {
                current = current->right;
            }

            //blad bereikt
            if(!current->left){
                if(current==nng_node->node){
                    continue;
                }

                //schrijf het character uit
                char newChar = current->value;
                fwrite(&newChar, sizeof(char), 1, fout);

                //update de boom
                update(find_node(nng_node, current), order_nodes, nng_node);
                update_tree(&tree, nng_node->node);

                //verschuif het window
                slide(&count, &window_index, window, order_nodes, (unsigned char) current->value, nng_node, &tree);

                current = tree;
            }

        }
        memset(text, '\0', 9);
    }

    free_tree(tree);
    free_list(nng_node);
    free(nextChar);
    free(text);
}
