#include "main.h"

int main(int argc, char* argv[]) {
    int opt;
    int algo_num = 0;
    bool decode = false, encode = false;


    //Parse options
    while((opt = getopt(argc, argv, "t:cd")) != -1){
        switch(opt){
            case 't':
                algo_num = (int) strtol(optarg, NULL, 10);
                break;
            case 'c':
                encode = true;
                break;
            case 'd':
                decode = true;
                break;
            default:
                return INCORRECT_OPTS;
        }
    }

    //Check options
    //encode and decode flags are not set, or both set
    if(decode&&encode||!encode&&!decode){
        return INCORRECT_OPTS;
    }

    //check if the correct algorithm has been chosen
    switch(algo_num){
        case STANDARD:
            break;
        case ADAPTIVE:
            break;
        case ADAPTIVE_SLIDING:
            break;
        case TWO_PASS_ADAPTIVE:
            break;
        case BLOCK_WISE:
            break;
        default:
            return INCORRECT_OPTS;
    }

    return 0;
}