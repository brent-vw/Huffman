//
// Created by Brent Van Wynsberge on 5/11/17.
//

#include "huff_node.h"

/**
 * Alloceer een nieuwe node
 * @return referentie naar de node
 */
huff_node* new_node(){
    huff_node* huff_tree = malloc(sizeof(*huff_tree));
    huff_tree->left = NULL;
    huff_tree->right = NULL;
    huff_tree->parent = NULL;
    huff_tree->value = 0;
    huff_tree->depth = 0;
    huff_tree->weight = -1;
    return huff_tree;
}

/**
 * Alloceer een nieuwe node en geef hem kinderen
 * @param left linkerkind
 * @param right rechterkind
 * @return referentie naar deze ouder
 */
huff_node* create_node(huff_node* left, huff_node* right){
    huff_node* node = malloc(sizeof(*node));
    node->left = left;
    node->right = right;
    node->parent = NULL;
    int weight = 0;
    if(left){
        weight += left->weight;
    }
    if(right){
        weight += right->weight;
    }
    node->weight = weight;
    node->value = -1;
    return node;
}

/**
 * Geef een volledige huffmanboom vrij
 * @param tree de wortel
 */
void free_tree(huff_node* tree){
    if(!tree){
        return;
    }
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}