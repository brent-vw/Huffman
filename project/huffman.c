//
// Created by Brent Van Wynsberge on 4/10/17.
//

#include <ntsid.h>
#include <time.h>
#include "huffman.h"
#include "input.h"

void huffman_encode(){
    clock_t start = clock();
    input* input = read_input();
    clock_t end = clock();

    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    printf("Time elapsed %.*f\n", 5, seconds);

    free_input(input);
}

void huffman_decode(){

}