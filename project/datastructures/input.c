//
// Created by Brent Van Wynsberge on 4/10/17.
//
#include "input.h"
#include "structs.h"


input* read_input(){
    input* in = allocate_input();
    int buffer[BUFFER_SIZE], c;
    FILE* f = fopen("/Users/brentvw/Projects/ugent/da3/project/test.txt", "r");
    int counter = 0;
    while ((c = fgetc(f))!=EOF){
//    while ((c = fgetc(stdin))!=EOF){
        //flush the buffer if it's full
        if(counter==BUFFER_SIZE){
            //first flush; just copy the data
            flush_buffer(in, counter, buffer);
            counter = 0;
        }

        //read the next character
        buffer[counter++] = c;
        //count the next character
        increment_node(c, in);

    }

    //flush the buffer one last time
    if(counter>0){
        flush_buffer(in, counter, buffer);
    }

    if(ferror(stdin)){
        perror("Failed to read from stdin");
        exit(-1);
    }
    return in;
}

void flush_buffer(input* input, int counter, int* buffer){
    int* old = input->content;
    size_t old_size = input->size;

    //reallocate
    input->size = input->size + counter;
    input->content = realloc(input->content, sizeof(int)*input->size);

    //check if reallocation was successful
    if(!input->content) {
        perror("Failed to reallocate content");
        free(old);
        free(input);
        exit(ALLOC_ERR);
    }

    for (int i = 0; i < counter; ++i) {
        input->content[old_size+i] = buffer[i];
    }
}

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

void free_input(input* in){
    free(in->content);
    free_nodes(in->nodes);
    free(in);
}

//TODO swap references
void move_node(node* toMove){
    if(!toMove->next){
        return;
    }

    node* next = toMove->next;
    if(next->weight > toMove->weight){
        return;
    }

    int oldWeight = toMove->weight;
    int oldValue = toMove->value;

    toMove->weight = next->weight;
    toMove->value = next->value;
    next->weight = oldWeight;
    next->value = oldValue;

    move_node(next);
}

void increment_node(int c, input* input){
    node *current = input->nodes;
    node* root = input->nodes;

    if(!current){
        input->nodes = allocate_node(c, input);
        input->nodes_size++;
        return;
    }

    while(current){
        if(current->value==c){
            current->weight++;
            move_node(current);
            return;
        }

        current = current->next;
    }

    input->nodes = allocate_node(c, input);
    input->nodes->next = root;
}

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

node* allocate_node(int c, input* in){
    node* new_node = malloc(sizeof(*new_node));
    new_node->value = c;
    new_node->weight = 1;
    new_node->next = NULL;
    in->nodes_size++;
    return new_node;
}

void free_nodes(node* root){
    node* current = root;
    while(current){
        node* tmp = current->next;
        free(current);
        current = tmp;
    }
}


