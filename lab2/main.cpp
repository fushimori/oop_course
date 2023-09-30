#include <iostream>
#include "include.h"

int main(){
    Twelve fp1(3);
    fp1.print(std::cout) << std::endl;

    Twelve fp2{'9','A'};
    fp2.print(std::cout) << std::endl;

    Twelve fp3("12A9");
    fp3.print(std::cout) << std::endl;

    Twelve fp1_cl(std::move(fp1));
    fp1_cl.print(std::cout) << std::endl;

    std::string s1,s2,s3;
    std::cin >> s1 >> s2;
    Twelve pn1(s1), pn2(s2);
    // pn1.print(std::cout) << std::endl;
    // pn2.print(std::cout) << std::endl;
    // std::cout << pn1.greater(pn2) << std::endl;
    pn1.add(pn2);
    pn1.print(std::cout) << std::endl;
    return 0;
}
