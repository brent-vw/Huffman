//
// Created by Brent Van Wynsberge on 1/12/17.
//
#include "block.h"
#include "../main.h"

/**
 * Decodeer 1 blok
 * @param fp referentie naar de input
 * @param fout referentie naar de output
 * @return true als er nog een blok volgt
 */
bool decode_block(FILE* fp, FILE* fout){
    //blokgrootte
    size_t block_size = BLOCK_SIZE;
    size_t max_size =  1 << (sizeof(unsigned char)*8);

    //init boom
    huff_node* tree = new_node();
    tree->value = NNG;
    order_node* nng_node = allocate_order_node(tree);
    order_node** order_nodes = calloc(max_size, sizeof(*order_nodes));

    //buffer
    char* text = calloc(9, sizeof(char));

    //initiele waarden
    bool nng_read = false;
    char* nextChar = calloc(9, sizeof(char));
    size_t bits_read = 0;

    //referentie naar de boom
    huff_node* current = tree;

    //gelezen grootte, gelezen character en gelezen nodes in het blok
    size_t size;
    char c;
    int j = 0;

    while ((size = fread(&c, sizeof(char), 1, fp))){
        //niets meer te lezen
        if(size<1){
            break;
        }

        //zet het character om naar zijn bitpatroon
        sprintf(text, BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(c));

        //overloop het patroon
        for (int i = 0; i < 8; ++i) {
            //huidige bit
            char bit = text[i];

            //nng node?
            if(!nng_read&&current==nng_node->node){
                nng_read = true;
            }

            //lees de bits en zet ze om naar het nieuwe character
            if(nng_read){
                nextChar[bits_read++] = bit;
                //Alle bits gelezen
                if(bits_read==8){
                    //maak het character
                    nng_read = false;
                    char newChar = (char) strtol(nextChar, 0, 2);
                    memset(nextChar, '\0', 9);
                    bits_read = 0;

                    //schrijf het weg
                    fwrite(&newChar, sizeof(char), 1, fout);

                    //incrementeer de block counter en kijk of dit het laatste element was
                    j++;
                    if(j==block_size){
                        free_tree(tree);
                        free_list(nng_node);
                        free(nextChar);
                        free(text);
                        return true;
                    }

                    //voeg het character toe aan de boom
                    nng(newChar, nng_node, order_nodes, (unsigned char) newChar);

                    //pas de referentie naar de boom aan
                    update_tree(&tree, nng_node->node);

                    current = tree;
                }
                continue;
            }

            //Doorloop de boom
            if(bit=='1'){
                current = current->left;
            } else {
                current = current->right;
            }

            //Blad bereikt
            if(!current->left){
                //Is het blad nng?
                if(current==nng_node->node){
                    continue;
                }

                //Schrijf het character uit
                fwrite(&current->value, sizeof(char), 1, fout);

                //Pas het node nummer in het blok aan en kijk of er nog gelzen moet worden
                j++;
                if(j==block_size){
                    free_tree(tree);
                    free_list(nng_node);
                    free(nextChar);
                    free(text);
                    return true;
                }

                //pas de frequentie aan in de boom
                update(order_nodes[(unsigned char)current->value], order_nodes, nng_node);

                //update de referentie
                update_tree(&tree, nng_node->node);

                current = tree;
            }
        }
        //maak de buffer leeg
        memset(text, '\0', 9);
    }

    //geef alles vrij
    free_tree(tree);
    free_list(nng_node);
    free(nextChar);
    free(text);
    return false;
}

void block_decode(){
    //debugging mogelijkheden
    FILE* fp = stdin;
    FILE* fout = stdout;

    //decodeer alle blokken
    while (decode_block(fp, fout)){
    }

    //geef de files vrij
    fclose(fp);
    fclose(fout);

}
