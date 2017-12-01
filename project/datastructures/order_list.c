//
// Created by Brent Van Wynsberge on 5/11/17.
//

#include "order_list.h"

/**
 * Alloceer een node die een ordenummer voorstelt
 * @param tree_element plaats in de boom
 * @return referentie naar de node
 */
order_node* allocate_order_node(huff_node *tree_element){
    order_node* node = malloc(sizeof(*node));
    node->node = tree_element;
    node->next = NULL;
    return node;
}

/**
 * Geef de lijst van de ordenummers vrij
 * @param root het eerste element
 */
void free_list(order_node* root){
    order_node* current = root;
    while (current!=NULL){
        order_node* tmp = current->next;
        free(current);
        current = tmp;
    }
}
