//
// Created by Brent Van Wynsberge on 29/11/17.
//
#include "adaptive.h"

void adaptive_decode(){
    //Files om te debuggen
    FILE* fp = stdin;
    FILE* fout = stdout;

    size_t max_size =  1 << (sizeof(unsigned char)*8);

    //init boom
    huff_node* tree = new_node();
    tree->value = NNG;
    order_node* nng_node = allocate_order_node(tree);
    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    //lees
    char* text = calloc(9, sizeof(char));

    //zet initiele gegevens gereed
    bool nng_read = false;
    char* nextChar = calloc(9, sizeof(char));
    size_t bits_read = 0;

    huff_node* current = tree;
    size_t size;
    char c;

    //lees tot de file gedaan is
    while ((size = fread(&c, sizeof(char), 1, fp))){

        if(size<1){
            break;
        }

        sprintf(text, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));
        for (int i = 0; i < 8; ++i) {

            char bit = text[i];

            if(!nng_read&&current==nng_node->node){
                nng_read = true;
            }

            //We hebben een nng gelezen, lees de volgende bits letterlijk in om het nieuwe character te bepalen
            if(nng_read){
                nextChar[bits_read++] = bit;
                //we hebben een character gelezen
                if(bits_read==8){
                    nng_read = false;
                    char newChar = (char) strtol(nextChar, 0, 2);
                    memset(nextChar, '\0', 9);
                    bits_read = 0;

                    //schrijf het nieuwe character uit
                    fwrite(&newChar, sizeof(char), 1, fout);

                    //update de boom
                    nng(newChar, nng_node, order_nodes, (unsigned char) newChar);

                    //verander de referentie naar de wortel van de boom naar de nieuwe wortel
                    update_tree(&tree, nng_node->node);
                    current = tree;
                }
                continue;
            }

            //blad bereikt
            if(!current->left){
                //Schrijf het gelezen character uit
                fwrite(&current->value, sizeof(char), 1, fout);

                //update de boom
                update(order_nodes[(unsigned char)current->value], order_nodes, nng_node);

                //verander de referentie naar de wortel van de boom naar de nieuwe wortel
                update_tree(&tree, nng_node->node);
                current = tree;
            }

            //doorloop de boom
            if(bit=='1'){
                current = current->left;
            } else {
                current = current->right;
            }
        }

        //wis de buffer
        memset(text, '\0', 9);
    }

    //geef alles terug vrij
    free_tree(tree);
    free_list(nng_node);
    free(nextChar);
    free(text);
}
