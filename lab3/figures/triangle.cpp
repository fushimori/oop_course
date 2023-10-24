#include "triangle.h"

Triangle::Triangle() : angles{Point(), Point(), Point()}, size_{0} {}

Triangle::Triangle(Point& p1, Point& p2, Point& p3){
    if(p1 == p2 || p1 == p3 || p2 == p3){
        throw std::logic_error("Same coordinates for different angles");
    }
    angles[0] = p1;
    angles[1] = p2;
    angles[2] = p3;
    size_ = 3;

} 

Point Triangle::center() const {
    std::cout << "Triangle center() " << std::endl;
    double x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 3.0, y_c / 3.0);
}

double Triangle::area() const {
    std::cout << "Triangle area() " << std::endl;
    if(size_ == 0){
        return 0.0;
    }
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
        size_ = right.size_;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& right){
    if (this != &right) {
        angles[0] = std::move(right.angles[0]);
        angles[1] = std::move(right.angles[1]);
        angles[2] = std::move(right.angles[2]);
        size_ = right.size_;
    }
    return *this;
}

bool Triangle::operator==(const Triangle& right) {
    if(size_ != right.size_){
        return false;
    }
    std::array<Point, 3> sorted_angles = {get_point(0), get_point(1), get_point(2)};
    std::array<Point, 3> sorted_right_angles = {right.get_point(0), right.get_point(1), right.get_point(2)};

    std::sort(sorted_angles.begin(), sorted_angles.end());
    std::sort(sorted_right_angles.begin(), sorted_right_angles.end());
    // for(size_t i = 0; i < 3; ++i){
    //     std::cout << "left" << sorted_angles[i] << std::endl;
    //     std::cout << "right" << sorted_right_angles[i] << std::endl;
    // }
    
    return sorted_angles == sorted_right_angles;
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
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    if(f.angles[0] == f.angles[1] || f.angles[0] == f.angles[2] || f.angles[1] == f.angles[2]){
        throw std::logic_error("Same coordinates for different angles");
    }
    f.size_ = 3;
    return is;
}

Triangle::operator double() const{
    return area();
}

size_t Triangle::size() const{
    return size_;
}

Point Triangle::get_point(const int i) const{
    if ( i < 0 || i > 2){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}