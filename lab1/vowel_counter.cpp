#include "vowel_counter.h"

int counter(std::string input){
    int count{0};
    for(char s: input){
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y') {
            count++;
        }
    }
    return count;
};