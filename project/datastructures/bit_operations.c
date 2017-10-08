//
// Created by Brent Van Wynsberge on 7/10/17.
//

#include "bit_operations.h"
unsigned int set_bit(unsigned int array, int index){
    return array |= 1 << (index%32);
}

unsigned int clear_bit(unsigned int array, int index){
    return array &= ~(1 << (index%32));
}

int test_bit(unsigned int array, int index){
    return ((array&(1<<(index%32)))!=0);
}
