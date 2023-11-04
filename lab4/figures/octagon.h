#pragma once

#include "figure.h"
#include <iostream>
#include "point.h"

template <class T>
class Octagon : public Figure<T> {

    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Octagon<F>& f);

    template<class F>
    friend std::istream& operator>>(std::istream& is, Octagon<F>& f);

public:
    Octagon();
    Octagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6, Point<T>& p7, Point<T>& p8);
    Octagon(const Octagon<T>& other);

    virtual T         area() const override;
    virtual Point<T>  center() const override;

    Point<T>  get_point(const int i) const;
    size_t    size() const;

    Octagon<T>& operator=(const Octagon<T>& right);
    Octagon<T>& operator=(Octagon<T>&& right);
    bool        operator==(const Octagon<T>& right) ;
    virtual     operator double() const override;

    ~Octagon(){};

    Point<T> angles[8];
    size_t size_;
};

template <class T>
Octagon<T>::Octagon() : 
    angles{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Octagon<T>::Octagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6, Point<T>& p7, Point<T>& p8) {
    std::array<Point<T>, 8> points = {p1, p2, p3, p4, p5, p6, p7, p8};
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

template <class T>
Octagon<T>::Octagon(const Octagon<T>& other){
    if (this != &other) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = other.angles[i];
        }
        size_ = other.size_;
    }
}

template <class T>
Point<T> Octagon<T>::center() const {
    std::cout << "Octagon center() " << std::endl;
    T x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 8.0, y_c / 8.0);
}

template <class T>
T Octagon<T>::area() const {
    std::cout << "Octagon area() " << std::endl;
    if(size_ == 0){
        return 0.0;
    }
    T x1 = angles[0].x_; T y1 = angles[0].y_;
    Point<T> center = this->center();
    T R = sqrt(pow((x1 - center.x_),2) + pow((y1 - center.y_),2));
    T r = R * cos(M_PI / 8);
    T area = 0.5 * 8 * R * r;
    return area;
}

template <class T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T>& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = right.angles[i];
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& right){
    if (this != &right) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = std::move(right.angles[i]);
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
bool Octagon<T>::operator==(const Octagon<T>& right) {
    if(size_ != right.size_){
        return false;
    }
    std::array<Point<T>, 8> sorted_angles;
    std::array<Point<T>, 8> sorted_right_angles;

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

template <class T>
std::ostream& operator<<(std::ostream& os, const Octagon<T>& f){
    os << "Octagon's coordinates:"<< std::endl;
    for(size_t i = 0; i < 8; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}

template <class T>
std::istream& operator>>(std::istream& is, Octagon<T>& f){
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

template <class T>
Octagon<T>::operator double() const{
    return area();
}

template <class T>
size_t Octagon<T>::size() const{
    return size_;
}

template <class T>
Point<T> Octagon<T>::get_point(const int i) const{
    if ( i < 0 || i > 7){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}