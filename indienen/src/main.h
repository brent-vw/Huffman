//
// Created by Brent Van Wynsberge on 3/10/17.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "constants.h"

#include "huffman/huffman.h"
#include "adaptive/adaptive.h"
#include "sliding/sliding.h"
#include "twopass/twopass.h"
#include "block/block.h"


typedef void (*FunctionPointer)(void);

#endif //PROJECT_MAIN_H
