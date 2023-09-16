// Вариант № 4
// Функция возвращает количество гласных букв в заданной строке (на английскрм).
// Входная строка будет состоять только из строчных букв и/или пробелов.

#include <iostream>
#include "vowel_counter.h"

int main(){
    std::string str;
    std::cout << "Enter your string: " << std::endl;
    
    std::getline(std::cin,str);
    std::cout << "Number of vowels in string: " << counter(str) << std::endl;
}
