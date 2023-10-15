#include "octagon.h"

Octagon::Octagon() : angles{Point(), Point(), Point(), Point(), Point(), Point(), Point(), Point()} {}

Octagon::Octagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6, Point& p7, Point& p8) :
         angles{p1, p2, p3, p4, p5, p6, p7, p8} {}

Point Octagon::center() const {
    std::cout << "Octagon center() " << std::endl;
    double x_c = 0, y_c = 0;
    for(size_t i = 0; i < 8; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 8.0, y_c / 8.0);
}

double Octagon::area() const {
    std::cout << "Octagon area() " << std::endl;
    double x1 = angles[0].x_; double y1 = angles[0].y_;
    Point center = this->center();
    double R = sqrt(pow((x1 - center.x_),2) + pow((y1 - center.y_),2));
    double r = R * cos(M_PI / 8);
    double area = 0.5 * 8 * R * r;
    return area;
}

Octagon& Octagon::operator=(const Octagon& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = right.angles[i];
        }
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = std::move(right.angles[i]);
        }
    }
    return *this;
}

bool Octagon::operator==(const Octagon& right){
    for(size_t i = 0; i < 8; ++i){
        if(angles[i] != right.angles[i]){
            return false;
        }
    }
    return true;
}


std::ostream& operator<<(std::ostream& os, const Octagon& f){
    os << "Octagon's coordinates:"<< std::endl;
    for(size_t i = 0; i < 8; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}
std::istream& operator>>(std::istream& is, Octagon& f){
    std::cout << "|Enter Octagon's coordinates|" << std::endl;
    for(size_t i = 0; i < 8; ++i){
        is >> f.angles[i];
    }
    return is;
}

Octagon::operator double() const{
    return area();
}

Point Octagon::get_point(const int i) const{
    if ( i <= 0 && 7 <= i){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}