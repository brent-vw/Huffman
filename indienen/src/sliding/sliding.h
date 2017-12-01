//
// Created by Brent Van Wynsberge on 29/11/17.
//

#ifndef PROJECT_SLIDING_H
#define PROJECT_SLIDING_H

#include "../adaptive/adaptive.h"

#define WINDOW_SIZE 255;

void sliding_encode();
void sliding_decode();

void downgrade(order_node* node, huff_node* destination, order_node** nodes, order_node* nng);
void slide(int *count, int *window_index, unsigned char *window, order_node **order_nodes, unsigned char value, order_node* nng, huff_node** tree);
bool onPath(huff_node* source, huff_node* destination);
huff_node* get_neighbour(huff_node* node);


#endif //PROJECT_SLIDING_H
