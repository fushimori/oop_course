#include <iostream>
#include <string>

#include "../figures/point.h"
#include "../vector/vector.h"
#include "../figures/triangle.h"
#include "../figures/hexagon.h"
#include "../figures/octagon.h"

// class Figure
// {
// public:
//     Figure();

//     virtual double area() const = 0;
//     virtual double center() const = 0;
//     ~Figure();
    
// };


int main(){

    // Point v1,v2,v3;

    // std::cin >> v1 >> v2 >> v3;
    // Point v4 = v2 = v3;
    // std::cout << v1 << v2 << v3 << v4 << std::endl;
    // Triangle tr(v1,v2,v3);
    // Hexagon tr1;
    // std::cin >> tr1;
    // std::cout << tr1;
    // std::cout << "Center : " <<  tr1.center() << std::endl;
    // std::cout << "Area : " << tr1.area() << std::endl;
    Point h_p1(0, 0);
    Point h_p2(1, 0);
    Point h_p3(1.5, sqrt(3)/2);
    Point h_p4(1, sqrt(3));
    Point h_p5(0, sqrt(3));
    Point h_p6(-0.5, sqrt(3)/2);

    Hexagon hex(h_p1, h_p2, h_p3, h_p4, h_p5, h_p6);
    double hexArea = hex.area();
    std::cout << "Hexagon's area: " << hexArea << std::endl;

    Point o_p1(0, 0);
    Point o_p2(1, 0);
    Point o_p3(1.5, sqrt(2));
    Point o_p4(1, sqrt(2) + 1);
    Point o_p5(0, sqrt(2) + 1);
    Point o_p6(-0.5, sqrt(2));
    Point o_p7(-1, 0);
    Point o_p8(-0.5, -sqrt(2));

    // Создаем объект класса Octagon и передаем ему координаты вершин
    Octagon oct(o_p1, o_p2, o_p3, o_p4, o_p5, o_p6, o_p7, o_p8);

    // Вычисляем и выводим площадь восьмиугольника
    double octArea = oct.area();
    std::cout << "Octagon's area: " << octArea << std::endl;

    return 0;


    return 0;
}