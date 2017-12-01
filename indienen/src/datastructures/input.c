//
// Created by Brent Van Wynsberge on 4/10/17.
//
#include <stdbool.h>
#include "input.h"

/**
 * Lees de boom in en maak een node aan voor elk character
 * @param count_chars tel de characters om er later een huffmanboom mee op te stellen
 * @return referentie naar de tekst
 */
input *read_input(bool count_chars) {
    input* in = allocate_input();
    char buffer[BUFFER_SIZE];
    size_t size;

    while ((size = fread(buffer, sizeof(char), BUFFER_SIZE, stdin))){
        //flush the buffer
        flush_buffer(in, size, buffer, count_chars);

        //we're done, eof was reached
        if(size<BUFFER_SIZE){
            break;
        }

    }

    if(ferror(stdin)){
        perror("Failed to read from stdin");
        exit(-1);
    }
    return in;
}

/**
 * Schrijf de buffer weg naar de input datastructuur
 * @param input bevat de nodes en de tekst
 * @param counter offset
 * @param buffer de buffer
 * @param count_chars of de frequenties aangepast moeten worden
 */
void flush_buffer(input* input, size_t counter, const char* buffer, bool count_chars){
    char* old = input->content;
    size_t old_size = input->size;

    //reallocate
    input->size = input->size + counter;
    input->content = realloc(input->content, sizeof(int)*input->size);

    //check if reallocation was successful -> indicatie op te veel geheugenverbruik
    if(!input->content) {
        perror("Failed to reallocate content");
        free(old);
        free(input);
        exit(ALLOC_ERR);
    }

    for (int i = 0; i < counter; ++i) {
        input->content[old_size+i] = buffer[i];
        if(count_chars) {
            increment_node(buffer[i], input);
        }
    }
}

/**
 * Alloceer geheugen voor de input
 * @return referentie naar de input
 */
input* allocate_input(){
    input* in;
    if(!(in=malloc(sizeof(input)))){
        perror("Failed to allocate input");
        exit(ALLOC_ERR);
    }

    //allocate content
    in->size = 0;
    in->content = calloc(BUFFER_SIZE, sizeof(int));

    if(!in->content){
        perror("Failed to allocate content");
        exit(ALLOC_ERR);
    }
    in->nodes = NULL;
    in->nodes_size = 0;
    return in;
}

/**
 * Geef de input terug vrij
 * @param in
 */
void free_input(input* in){
    free(in->content);
    free_nodes(in->nodes);
    free(in);
}

/**
 * Verplaats een node zodat hij relatief op de juiste plaats komt te staan
 * @param toMove
 */
void move_node(node* toMove){
    if(!toMove->next){
        return;
    }

    //kijk of het element op de juiste plaats staat
    node* next = toMove->next;
    if(next->weight > toMove->weight){
        return;
    }

    //wissel de referenties om
    int oldWeight = toMove->weight;
    char oldValue = toMove->value;

    toMove->weight = next->weight;
    toMove->value = next->value;
    next->weight = oldWeight;
    next->value = oldValue;

    //ga door
    move_node(next);
}

/**
 * Verhoog de de count van het character met 1
 * @param c het getelde character
 * @param input de input
 */
void increment_node(char c, input* input){
    node *current = input->nodes;
    node* root = input->nodes;

    //eerste character
    if(!current){
        input->nodes = allocate_node(c, input);
        return;
    }

    //zoek het character
    while(current){
        if(current->value==c){
            current->weight++;
            move_node(current);
            return;
        }

        current = current->next;
    }

    //verschuif
    input->nodes = allocate_node(c, input);
    input->nodes->next = root;
}

/**
 * Wissel alle nodes om zodat de hoogste gewichten eerst komen
 * @param in
 */
void reverse_nodes(input* in){
    node* head = in->nodes;
    node* previous = NULL;

    while(head){
        //move reference
        node* next = head->next;
        head->next = previous;
        //swap
        previous = head;
        head = next;
    }
    in->nodes = previous;
}

/**
 * Vraag geheugen voor een node
 * @param c het character
 * @param in de lijst
 * @return de node
 */
node* allocate_node(char c, input* in){
    in->nodes_size++;
    return _allocate_node(c);
}

/**
 * Defaultwaarden voor de node
 * @param c character
 * @return de node
 */
node* _allocate_node(char c){
    node* new_node = malloc(sizeof(*new_node));
    new_node->value = c;
    new_node->weight = 1;
    new_node->next = NULL;
    return new_node;
}

/**
 * Geef de nodes terug vrij
 * @param root het eerste element van de gelinkte lijst
 */
void free_nodes(node* root){
    node* current = root;
    while(current->next){
        node* tmp = current->next;
        free(current);
        current = tmp;
    }
}


