//
// Created by Brent Van Wynsberge on 5/11/17.
//

#ifndef PROJECT_ORDER_LIST_H
#define PROJECT_ORDER_LIST_H
#include "structs.h"
order_node* allocate_order_node(huff_node *tree_element);
void free_list(order_node* root);
#endif //PROJECT_ORDER_LIST_H
