#include "hexagon.h"

Hexagon::Hexagon() : angles{Point(), Point(), Point(), Point(), Point(), Point()} {}

Hexagon::Hexagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6) :
         angles{p1, p2, p3, p4, p5, p6} {}

Point Hexagon::center() const {
    std::cout << "Hexagon center() " << std::endl;
    double x_c = 0, y_c = 0;
    for(size_t i = 0; i < 6; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 6.0, y_c / 6.0);
}

double Hexagon::area() const {
    std::cout << "Hexagon area() " << std::endl;
    double x1 = angles[0].x_; double y1 = angles[0].y_;
    Point center = this->center();
    double R = sqrt(pow((x1 - center.x_),2) + pow((y1 - center.y_),2));
    double r = R * cos(M_PI / 6);
    double area = 0.5 * 6 * R * r;
    return area;
}

Hexagon& Hexagon::operator=(const Hexagon& right){
    if (this != &right) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = right.angles[i];
        }
    }
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& right){
    if (this != &right) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = std::move(right.angles[i]);
        }
    }
    return *this;
}

bool Hexagon::operator==(const Hexagon& right){
    for(size_t i = 0; i < 6; ++i){
        if(angles[i] != right.angles[i]){
            return false;
        }
    }
    return true;
}


std::ostream& operator<<(std::ostream& os, const Hexagon& f){
    os << "Hexagon's coordinates:"<< std::endl;
    for(size_t i = 0; i < 6; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}

std::istream& operator>>(std::istream& is, Hexagon& f){
    std::cout << "|Enter Hexagon's coordinates|" << std::endl;
    for(size_t i = 0; i < 6; ++i){
         is >> f.angles[i];
    }
    return is;
}

Hexagon::operator double() const{
    return area();
}

Point Hexagon::get_point(const int i) const{
    if ( i <= 0 && 5 <= i){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}