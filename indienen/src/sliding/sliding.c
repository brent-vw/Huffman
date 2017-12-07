//
// Created by Brent Van Wynsberge on 29/11/17.
//

#include "sliding.h"

/**
 * Verwijder de node omdat zijn gewicht nu 0 is
 * @param node de te verwijderen node
 * @param nodes dictionary
 * @param nng linked list
 */
void delete(order_node* node, order_node** nodes, order_node* nng){
    //De oude ouder dit wordt de nieuwe nng locatie
    huff_node* oldParent = node->node;

    //verwijder dictionary ref
    if(oldParent->right==nng->node){
        nodes[(unsigned char) oldParent->left->value] = NULL;
    } else {
        nodes[(unsigned char) oldParent->right->value] = NULL;
    }

    //wijzig de waarde naar nng
    oldParent->value = NNG;

    //geef de 2 te verwijderen nodes vrij
    order_node* current = nng->next;
    while (oldParent!=current->node){
        order_node* newNext = current->next;
        free(current);
        current = newNext;
    }

    //wissel referenties
    nng->node = oldParent;
    nng->next = current->next;
    free(current);

    //zoek de nieuwe buur
    current = nng->next->next;
    order_node* previous = nng->next;
    while (current->node!=nng->node->parent){
        previous = current;
        current = current->next;
    }

    //verwissel zodat ze buren worden
    if(previous!=nng->next){
        swap(current, nng->next->next, nodes);
    }

    //geef alles vrij
    free(oldParent->left);
    free(oldParent->right);
    oldParent->left = NULL;
    oldParent->right = NULL;
}

/**
 * Kijk of dit pad naar de gezochte node wijst
 * @param source de wortel
 * @param destination de bestemming
 * @return
 */
bool onPath(huff_node* source, huff_node* destination){
    if(!source){
        return false;
    }
    if(source==destination){
        return true;
    }
    return onPath(source->left, destination) || onPath(source->right, destination);
}

/**
 * zoek de meest linkse node met dezelfde diepte
 * wissel deze om
 * verminder het gewicht met 1
 * als het nieuwe gewicht == 0 -> verwijder uit boom
 * herhaal voor ouder
 * @param node
 * @parm nodes
 * @param nng
 */
void downgrade(order_node* node, huff_node* destination, order_node** nodes, order_node* nng){
    //Referentie naar de node zelf
    huff_node* h_n = node->node;

    //de oude ouder
    huff_node* oldParent = h_n->parent;

    //zoek het meest linkse
    order_node* current = nng;
    while (current->node->weight<h_n->weight){
        current = current->next;
    }

    //wissel indien ze niet hetzelfde zijn of het een kind is (we gaan verder op het pad van het kind)
    if(current!=node){
        if(current->node!=h_n->left&&current->node!=h_n->right){
            swap(current, node, nodes);
        }
    }

    //als de ouders hetzelfde blijven zijn we klaar
    if(h_n->parent==oldParent) {
        h_n->weight--;
    } else {
        //het kind is van plaats gewisseld dit pad is niet langer geldig
        while(!onPath(oldParent, destination)){
            oldParent->weight++;
            oldParent = oldParent->parent;
        }
        h_n = oldParent;
    }

    //verwijder het kind
    if(h_n->weight==0){
        delete(find_node(nng, h_n), nodes, nng);
    //zolang we niet klaar zijn gaan we door voor de kinderen
    } else if(h_n!=destination){
        if(onPath(h_n->left, destination)){
            downgrade(find_node(nng, h_n->left), destination, nodes, nng);
        } else {
            downgrade(find_node(nng, h_n->right), destination, nodes, nng);
        }
    }

}

/**
 * Verlaag de node die uit het window verdwijnt en voeg de nieuwe node aan het window toe
 * @param count check if het window al volgeschreven werd
 * @param window_index index in het window
 * @param window het window
 * @param order_nodes dictionary
 * @param value index in het dictionary
 * @param nng gelinkte lijst
 * @param tree de huffman boom
 */
void slide(int *count, int *window_index, unsigned char *window, order_node **order_nodes, unsigned char value, order_node* nng, huff_node** tree) {
    int window_size = WINDOW_SIZE;
    *count = *count + 1;

    if((float)(*count)/window_size>1){
        update_tree(tree, nng->node);
        huff_node* node = order_nodes[window[*window_index]]->node;
        downgrade(find_node(nng, *tree), node, order_nodes, nng);

        update_tree(tree, nng->node);
    }

    window[*window_index] = value;
    *window_index = (*window_index + 1) % window_size;
}


