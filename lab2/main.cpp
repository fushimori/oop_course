// Вариант № 10
// Создать класс Twelve для работы с беззнаковыми целыми двенадцатиричными числами, 
// используя для представления числа массив из элементов типа unsigned char, 
// каждый из которых является двенадцатиричными цифрой. Младшая цифра имеет меньший индекс 
// (единицы – в нулевом элементе массива).

#include <iostream>
#include "include.h"

int main(){
        std::string s1,s2,s3;
        std::cout << "Enter strings:" << std::endl; 
        std::cin >> s1 >> s2;
        Twelve pn1(s1), pn2(s2);
        // pn1.print(std::cout) << std::endl;
        // pn2.print(std::cout) << std::endl;
        // std::cout << pn1.greater(pn2) << std::endl;
        try{
            Twelve pn12 = pn1.add(pn2);
            std::cout << "Sum:" << std::endl; 
            pn12.print(std::cout) << std::endl;

            Twelve pn13 = pn1.subtract(pn2);
            std::cout << "Dif:" << std::endl; 
            pn13.print(std::cout) << std::endl;
        }
        catch(std::exception &e){
            std::cerr << "exception: " << e.what() << std::endl;
        }
    return 0;
}
