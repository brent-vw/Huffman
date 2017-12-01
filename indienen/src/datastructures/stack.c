//
// Created by Brent Van Wynsberge on 7/10/17.
//
#include "stack.h"

/**
 * Maak de stack aan
 * @param capacity maximum aantal elementen
 * @return referentie naar de stack
 */
stack *allocate_stack(size_t capacity) {
    stack *ptr = malloc(sizeof(stack));

    //Init
    ptr->capacity = capacity;
    ptr->top = -1;

    //Array van de nodes
    huff_node** stack = malloc(sizeof(huff_node*)*capacity);
    for (int i = 0; i < capacity; ++i) {
        stack[i] = NULL;
    }
    ptr->stack = stack;

    return ptr;
}

/**
 * Is de stack leeg?
 * @param stack
 * @return true indien leeg
 */
bool isEmpty(stack* stack){
    return stack->top < 0;
}

/**
 * Zit de stack vol?
 * @param stack
 * @return true indien vol
 */
bool isFull(stack* stack){
    return stack->top >= (int) stack->capacity;
}

/**
 * Geef de stack terug vrij
 * @param stack
 */
void free_stack(stack *stack) {
    free(stack->stack);
    free(stack);
}

/**
 * Zet een element op de stack
 * @param stack
 * @param node
 */
void push(stack *stack, huff_node *node) {
    //Increment the top location and add to the stack if it's not full
    if(!isFull(stack)){
        stack->stack[++stack->top] = node;
    } else {
        fprintf(stderr, "Stack is full; size: %i, head: %i\n", (int) stack->capacity, stack->top);
    }
}

/**
 * Zet alle elementen van een andere stack op de stack
 * @param ptr te vullen stack
 * @param data te ledigen stack
 */
void pushAll(stack *ptr, stack *data){
    while(!isEmpty(data)){
        push(ptr, pop(data));
    }
}

/**
 * Kijk naar de top van de stapel zonder het te poppen
 * @param stack
 * @return de top
 */
huff_node *peek(stack *stack) {
    //peek if the stack is not empty
    if(!isEmpty(stack)){
        return stack->stack[stack->top];
    }
    return NULL;
}

/**
 * Verwijder de top van de stapel
 * @param stack
 * @return de top
 */
huff_node *pop(stack *stack) {
    //Get from the stack en decrement the top location
    if(!isEmpty(stack)){
        huff_node* value = stack->stack[stack->top--];
        return value;
    }
    return NULL;
}

/**
 * Bouw de stack op van een gegeven input
 * @param in de input
 * @param stack de te vullen stack
 * @return de hoogste character waarde (om het dictionary op te kunnen bouwen)
 */
int build_stack(input* in, stack* stack){
    //Van groot naar klein
    reverse_nodes(in);
    node* current = in->nodes;

    int max = -1;
    int counter = 0;

    //Maak voor elk inputelement een nieuw blad in de huffman boom
    while(current){
        huff_node* node = malloc(sizeof(*node));
        node->left = NULL;
        node->right = NULL;
        node->value = current->value;
        node->weight = current->weight;

        push(stack, node);
        max = node->value > max ? node->value : max;

        current = current->next;
        counter++;
    }

    //Er is slechts 1 character, maak een fake boom
    if(counter==1){
        huff_node* node = malloc(sizeof(*node));
        node->left = NULL;
        node->right = NULL;
        node->value = -1;
        node->weight = 0;
        push(stack, node);
    }

    return max;
}
