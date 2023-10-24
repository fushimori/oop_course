#include "octagon.h"

Octagon::Octagon() : 
    angles{Point(), Point(), Point(), Point(), Point(), Point(), Point(), Point()}, size_{0} {}

Octagon::Octagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6, Point& p7, Point& p8) {
    std::array<Point, 8> points = {p1, p2, p3, p4, p5, p6, p7, p8};
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (points[i] == points[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
        angles[i] = points[i];
    }
    size_ = 8;
}

Point Octagon::center() const {
    std::cout << "Octagon center() " << std::endl;
    double x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 8.0, y_c / 8.0);
}

double Octagon::area() const {
    std::cout << "Octagon area() " << std::endl;
    if(size_ == 0){
        return 0.0;
    }
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
        size_ = right.size_;
    }
    return *this;
}

Octagon& Octagon::operator=(Octagon&& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = std::move(right.angles[i]);
        }
        size_ = right.size_;
    }
    return *this;
}

bool Octagon::operator==(const Octagon& right) {
    if(size_ != right.size_){
        return false;
    }
    std::array<Point, 8> sorted_angles;
    std::array<Point, 8> sorted_right_angles;

    for (int i = 0; i < 8; i++) {
        sorted_angles[i] = get_point(i);
        sorted_right_angles[i] = right.get_point(i);
    }

    std::sort(sorted_angles.begin(), sorted_angles.end());
    std::sort(sorted_right_angles.begin(), sorted_right_angles.end());

    // for (int i = 0; i < 8; i++) {
    //     std::cout << "left" << sorted_angles[i] << std::endl;
    //     std::cout << "right" << sorted_right_angles[i] << std::endl;
    // }

    return sorted_angles == sorted_right_angles;
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
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (f.angles[i] == f.angles[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
    }
    f.size_ = 8;
    return is;
}

Octagon::operator double() const{
    return area();
}

size_t Octagon::size() const{
    return size_;
}

Point Octagon::get_point(const int i) const{
    if ( i < 0 || i > 7){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}