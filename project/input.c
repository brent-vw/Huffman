//
// Created by Brent Van Wynsberge on 4/10/17.
//

#include "input.h"

input* read_input(){
    input* in = allocate_input();
    int buffer[BUFFER_SIZE], c;

    int counter = 0;
    while ((c = fgetc(stdin))!=EOF){
        //flush the buffer if it's full
        if(counter==BUFFER_SIZE){
            //first flush; just copy the data
            if(in->size==0){
                memcpy(in->content, buffer, BUFFER_SIZE);
                in->size = BUFFER_SIZE;
            } else { //consecutive flush; concat both arrays and free the old array
                flush_buffer(in, counter, buffer);
            }
            counter = 0;
        }

        //read the next character
        buffer[counter++] = c;
        //count the next character
        in->nodes=increment_node(c, in->nodes);

    }

    //flush the buffer one last time
    if(counter>0){
        flush_buffer(in, counter, buffer);
    }

    node* current = in->nodes;
    while(current){
        printf("%c: %i\n", (char)current->value, current->weight);
        current = current->next;
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

    //copy the new data
    memcpy(&input->content[old_size],buffer,counter);
}

void count_char(int c, input* in){

}

input* allocate_input(){
    input* in;
    if(!(in=malloc(sizeof(*in)))){
        perror("Failed to allocate input");
        exit(ALLOC_ERR);
    }

    //allocate content
    in->size = 0;
    in->content = malloc(sizeof(int)*BUFFER_SIZE);

    if(!in->content){
        perror("Failed to allocate content");
        exit(ALLOC_ERR);
    }
    in->nodes = NULL;
    return in;
}

void free_input(input* in){
    free(in->content);
    free_nodes(in->nodes);
    free(in);
}

node* increment_node(int c, node* root){
    node *current = root, *previous = root;

    if(!current){
        return allocate_node(c, NULL);
    }

    while(current){
        previous = current;

        if(current->value==c){
            current->weight++;
            return root;
        }

        current = current->next;
    }

    previous->next = allocate_node(c, previous);
    return root;

}

node* allocate_node(int c, node* previous){
    node* new_node = malloc(sizeof(node));
    new_node->value = c;
    new_node->weight = 1;
    new_node->next = NULL;
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


