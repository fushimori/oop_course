#include <iostream>
#include <string>
#include "vector/vector.h"

#include "figures/point.h"
#include "figures/figure.h"
#include "figures/triangle.h"
#include "figures/hexagon.h"
#include "figures/octagon.h"


template<typename T>
double sum_area(const Vector<T>& arr){
    double sum = 0;
    for(int i = 0; i < arr.size(); ++i){
        sum += arr.get(i)->area();
    }
    return sum;
}


int main(){
    std::unique_ptr<Triangle<double>> t = std::make_unique<Triangle<double>>();
    std::unique_ptr<Hexagon<double>> h = std::make_unique<Hexagon<double>>();
    std::unique_ptr<Octagon<double>> o = std::make_unique<Octagon<double>>();
    
    std::cin >> *t >> *h >> *o;
    std::cout << *t << *h << *o;

    // Triangle<double> t;
    // Hexagon<double> h;
    // Octagon<double> o;
    // std::cin >> t >> h >> o;
    // auto t_ptr = std::unique_ptr<Triangle<double>>(new Triangle<double>(t));
    // auto h_ptr = std::unique_ptr<Hexagon<double>>(new Hexagon<double>(h));
    // auto o_ptr = std::unique_ptr<Octagon<double>>(new Octagon<double>(o));
    // std::cin >> *t_ptr >> *h_ptr >> *o_ptr;

    Vector<std::unique_ptr<Figure<double>>> arr;

    arr.push_back(std::move(t));
    arr.push_back(std::move(h));
    arr.push_back(std::move(o));

    // arr.remove(0);
    // arr.push_back(&h);
    // arr.push_back(&o);
    // std::cout << static_cast<double>(*(arr.get(0))) << std::endl;
    // std::cout << (arr.get(0))->area() << std::endl;
    // std::cout << t;

    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Geometric center of figure " << i + 1 << ": " << arr.get(i)->center() << std::endl;
        std::cout << "Area of figure " << i + 1 << ": " << arr.get(i)->area() << std::endl;
    }

    std::cout << "Total area of figures: " << sum_area(arr) << std::endl;
    arr.remove(0);
    std::cout << "Total area of figures: " << sum_area(arr) << std::endl;
    
    Point<double> p1(1,2), p2(-1,4), p3(3,2), p4(1,-2), p5(-1,2) ,p6(-4,2), p7(3,-1), p8(-1,-4);

    auto h_p1 = std::make_unique<Hexagon<double>>(p3,p7,p5,p1,p4,p8);
    auto o_p1 = std::make_unique<Octagon<double>>(p1,p2,p3,p4,p5,p6,p7,p8);
    arr.push_back(std::move(o_p1));
    arr.push_back(std::move(h_p1));


    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Geometric center of figure " << i + 1 << ": " << arr.get(i)->center() << std::endl;
        std::cout << "Area of figure " << i + 1 << ": " << arr.get(i)->area() << std::endl;
    }
    return 0;
}
