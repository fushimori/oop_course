#include "triangle.h"

Triangle::Triangle() : angles{Point(), Point(), Point()} {}

Triangle::Triangle(Point& p1, Point& p2, Point& p3) : angles{p1, p2, p3}  {}

Point Triangle::center() const {
    std::cout << "Triangle center() " << std::endl;
    double x_c = 0, y_c = 0;
    for(size_t i = 0; i < 3; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 3.0, y_c / 3.0);
}

double Triangle::area() const {
    std::cout << "Triangle area() " << std::endl;
    double x1 = angles[0].x_;double y1 = angles[0].y_;
    double x2 = angles[1].x_;double y2 = angles[1].y_;
    double x3 = angles[2].x_;double y3 = angles[2].y_;

    double area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    return area;
}

Triangle& Triangle::operator=(const Triangle& right){
    if (this != &right) {
        angles[0] = right.angles[0];
        angles[1] = right.angles[1];
        angles[2] = right.angles[2];
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& right){
    if (this != &right) {
        angles[0] = std::move(right.angles[0]);
        angles[1] = std::move(right.angles[1]);
        angles[2] = std::move(right.angles[2]);
    }
    return *this;
}

bool Triangle::operator==(const Triangle& right){
    return angles[0] == right.angles[0] &&
           angles[1] == right.angles[1] &&
           angles[2] == right.angles[2];
}

std::ostream& operator<<(std::ostream& os, const Triangle& f){
    os << "Triangle's coordinates:"<< std::endl;
    for(size_t i = 0; i < 3; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}
std::istream& operator>>(std::istream& is, Triangle& f) {
    std::cout << "|Enter Triangle's coordinates|" << std::endl;
    for (size_t i = 0; i < 3; ++i) {
         is >> f.angles[i];
    }
    return is;
}

Triangle::operator double() const{
    return area();
}

Point Triangle::get_point(const int i) const{
    if ( i <= 0 && 3 <= i){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}