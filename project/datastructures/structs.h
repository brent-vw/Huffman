//
// Created by Brent Van Wynsberge on 7/10/17.
//

#ifndef PROJECT_STRUCTS_H
#define PROJECT_STRUCTS_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../constants.h"

/**
 * De huffman boom
 */
typedef struct huff_node huff_node;
struct huff_node{
    int weight; //het gewicht van de top
    int depth; //de diepte van de top (niet altijd gebruikt)
    char value; //de character waarde
    huff_node *left, *right, *parent; //de kinderen en de ouder
};

/*
 * De stack van huffman toppen
 */
typedef struct stack stack;
struct stack{
    huff_node** stack;  //De elementen
    size_t capacity;    //Capaciteit
    int top;            //Referentie naar het peek/pop element
};

/*
 * Een statische code van een element van de huffman boom
 */
typedef struct code code;
struct code{
    char key;           //Sleutelwaarde
    char* code;         //De code
    int code_length;    //Lengte van de code
};

/*
 * Node om bij de input te gebruiken (tellen)
 */
typedef struct node node;
struct node{
    char value;         //waarde
    int weight;         //occurences
    node* next;         //volgende
};

/*
 * Representatie van ordenummers
 */
typedef struct order_node order_node;
struct order_node{
    huff_node* node;    //De node in de huffmanboom
    order_node* next;   //het volgende element
};

typedef struct {
    size_t size;        //Groote van de inhoud
    char* content;      //De inhoud
    size_t nodes_size;  //Aantal nodes
    node* nodes;        //Gelinkte lijst van de characters
} input;

#endif //PROJECT_STRUCTS_H
