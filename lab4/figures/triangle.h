#pragma once

#include "figure.h"
#include <iostream>
#include "point.h"

template <class T>
class Triangle : public Figure<T> 
{

    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Triangle<F>& f);

    template<class F>
    friend std::istream& operator>>(std::istream& is, Triangle<F>& f);

public:
    Triangle();
    Triangle(Point<T>& p1, Point<T>& p2, Point<T>& p3);
    Triangle(const Triangle<T>& other);

    virtual T         area() const override;
    virtual Point<T>  center() const override;

    Point<T>  get_point(const int i) const;
    size_t    size() const;

    Triangle<T>& operator=(const Triangle<T>& right);
    Triangle<T>& operator=(Triangle<T>&& right);
    bool         operator==(const Triangle<T>& right);
    virtual      operator double() const override;

    ~Triangle(){};

    Point<T> angles[3];
    size_t size_;
};

template <class T>
Triangle<T>::Triangle() : angles{Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Triangle<T>::Triangle(Point<T>& p1, Point<T>& p2, Point<T>& p3){
    if(p1 == p2 || p1 == p3 || p2 == p3){
        throw std::logic_error("Same coordinates for different angles");
    }
    angles[0] = p1;
    angles[1] = p2;
    angles[2] = p3;
    size_ = 3;
} 

template <class T>
Triangle<T>::Triangle(const Triangle<T>& other){
    if (this != &other) {
        angles[0] = other.angles[0];
        angles[1] = other.angles[1];
        angles[2] = other.angles[2];
        size_ = other.size_;
    }
}

template <class T>
Point<T> Triangle<T>::center() const {
    std::cout << "Triangle center() " << std::endl;
    T x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point<T>(x_c / 3.0, y_c / 3.0);
}

template <class T>
T Triangle<T>::area() const {
    std::cout << "Triangle area() " << std::endl;
    if(size_ == 0){
        return 0.0;
    }
    T x1 = angles[0].x_;T y1 = angles[0].y_;
    T x2 = angles[1].x_;T y2 = angles[1].y_;
    T x3 = angles[2].x_;T y3 = angles[2].y_;

    T area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
    return area;
}

template <class T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T>& right){
    if (this != &right) {
        angles[0] = right.angles[0];
        angles[1] = right.angles[1];
        angles[2] = right.angles[2];
        size_ = right.size_;
    }
    return *this;
}

template <class T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>&& right){
    if (this != &right) {
        angles[0] = std::move(right.angles[0]);
        angles[1] = std::move(right.angles[1]);
        angles[2] = std::move(right.angles[2]);
        size_ = right.size_;
    }
    return *this;
}

template <class T>
bool Triangle<T>::operator==(const Triangle<T>& right) {
    if(size_ != right.size_){
        return false;
    }
    std::array<Point<T>, 3> sorted_angles = {get_point(0), get_point(1), get_point(2)};
    std::array<Point<T>, 3> sorted_right_angles = {right.get_point(0), right.get_point(1), right.get_point(2)};

    std::sort(sorted_angles.begin(), sorted_angles.end());
    std::sort(sorted_right_angles.begin(), sorted_right_angles.end());
    // for(size_t i = 0; i < 3; ++i){
    //     std::cout << "left" << sorted_angles[i] << std::endl;
    //     std::cout << "right" << sorted_right_angles[i] << std::endl;
    // }
    
    return sorted_angles == sorted_right_angles;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Triangle<T>& f){
    os << "Triangle's coordinates:"<< std::endl;
    for(size_t i = 0; i < 3; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Triangle<T>& f) {
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

template <class T>
Triangle<T>::operator double() const{
    return area();
}

template <class T>
size_t Triangle<T>::size() const{
    return size_;
}

template <class T>
Point<T> Triangle<T>::get_point(const int i) const{
    if ( i < 0 || i > 2){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}