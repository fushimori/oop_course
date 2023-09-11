#include <iostream>
#include "vowel_counter.h"

int main(){
    std::string str;
    std::cout << "Enter your string: " << std::endl;
    
    std::getline(std::cin,str);
    std::cout << "Number of vowels in string: " << counter(str) << " sussyy" << std::endl;
}
