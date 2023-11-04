#include <iostream>
#include <string>
#include "vector/vector.h"

#include "figures/point.h"
#include "figures/figure.h"
#include "figures/triangle.h"
#include "figures/hexagon.h"
#include "figures/octagon.h"


double sum_area(const Vector& arr){
    double sum = 0;
    for(int i = 0; i < arr.size(); ++i){
        sum += arr.get(i)->area();
    }
    return sum;
}


int main(){
    Triangle t;
    Hexagon h;
    Octagon o;
    std::cin >> t >> h >> o; // >> o;

    Vector arr;

    arr.push_back(&t);
    arr.push_back(&h);
    arr.push_back(&o);

    // arr.remove(0);
    // arr.push_back(&h);
    // arr.push_back(&o);
    // std::cout << static_cast<double>(*(arr.get(0))) << std::endl;
    // std::cout << (arr.get(0))->center() << std::endl;
    // std::cout << t;

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Geometric center of figure " << i + 1 << ": " << arr.get(i)->center() << std::endl;
        std::cout << "Area of figure " << i + 1 << ": " << arr.get(i)->area() << std::endl;
    }

    std::cout << "Total area of figures: " << sum_area(arr) << std::endl;
    arr.remove(0);
    std::cout << "Total area of figures: " << sum_area(arr) << std::endl;
    
    Point p1(1,2), p2(-1,2), p3(1,5), p4(1,3), p5(-1,-2) ,p6(-4,2), p7(-1,7), p8(2,-2);
    Octagon o1(p1,p2,p3,p4,p5,p6,p7,p8);
    Hexagon h1(p3,p7,p2,p1,p4,p8);

    arr.push_back(&o1);
    arr.push_back(&h1);

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Geometric center of figure " << i + 1 << ": " << arr.get(i)->center() << std::endl;
        std::cout << "Area of figure " << i + 1 << ": " << arr.get(i)->area() << std::endl;
    }
    return 0;
}
