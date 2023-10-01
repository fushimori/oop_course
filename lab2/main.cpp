#include <iostream>
#include "include.h"

int main(){
        // Twelve fp1(3);
        // fp1.print(std::cout) << std::endl;

        // Twelve fp2{'9','A'};
        // fp2.print(std::cout) << std::endl;

        // Twelve fp3("12A9");
        // fp3.print(std::cout) << std::endl;

        // Twelve fp1_cl(std::move(fp1));
        // fp1_cl.print(std::cout) << std::endl;

        // std::string str(5,'1');
        // Twelve tw1{str};
        // Twelve tw2(10,'0');
        
        // tw1.print(std::cout) << std::endl;
        // tw2.print(std::cout) << std::endl;

        // Twelve tw3 = tw1.add(tw2);
        // std::string rez{"1000"};
        // tw3.print(std::cout) << std::endl;

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
