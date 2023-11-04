#pragma once

#include "figure.h"
#include <iostream>
#include "point.h"

template<class T>
class Hexagon : public Figure<T> 
{
    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Hexagon<F>& f);

    template<class F>
    friend std::istream& operator>>(std::istream& is, Hexagon<F>& f);

public:
    Hexagon();
    Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6);
    Hexagon(const Hexagon<T>& other);

    virtual T area() const override;
    virtual Point<T>  center() const override;

    Point<T>  get_point(const int i) const;
    size_t size() const;

    Hexagon<T>& operator=(const Hexagon<T>& right);
    Hexagon<T>& operator=(Hexagon<T>&& right);
    bool     operator==(const Hexagon<T>& right) ;
    virtual  operator double() const override;

    ~Hexagon(){};

    Point<T> angles[6];
    size_t size_;
};

template <class T>
Hexagon<T>::Hexagon() : angles{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Hexagon<T>::Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5, Point<T>& p6) {
    std::array<Point<T>, 6> points = {p1, p2, p3, p4, p5, p6};
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (points[i] == points[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
        angles[i] = points[i];
    }
    size_ = 6;
}

template <class T>
Hexagon<T>::Hexagon(const Hexagon<T>& other){
    if (this != &other) {
        for(size_t i = 0; i < 8; ++i){
            angles[i] = other.angles[i];
        }
        size_ = other.size_;
    }
}

template <class T>
Point<T> Hexagon<T>::center() const {
    std::cout << "Hexagon center() " << std::endl;
    T x_c = 0, y_c = 0;
    for(size_t i = 0; i < size_; ++i){
        x_c += angles[i].x_;
        y_c += angles[i].y_;
    }
    return Point(x_c / 6.0, y_c / 6.0);
}

template <class T>
T Hexagon<T>::area() const {
    std::cout << "Hexagon area() " << std::endl;
    if(size_ == 0){
        return 0.0;
    }
    T x1 = angles[0].x_; T y1 = angles[0].y_;
    Point<T> center = this->center();
    double R = sqrt(pow((x1 - center.x_),2) + pow((y1 - center.y_),2));
    double r = R * cos(M_PI / 6);
    double area = 0.5 * 6 * R * r;
    return area;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& right){
    if (this != &right) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = right.angles[i];
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& right){
    if (this != &right) {
        for(size_t i = 0; i < 6; ++i){
            angles[i] = std::move(right.angles[i]);
        }
        size_ = right.size_;
    }
    return *this;
}

template <class T>
bool Hexagon<T>::operator==(const Hexagon<T>& right) {
    if(size_ != right.size_){
        return false;
    }
    std::array<Point<T>, 6> sorted_angles;
    std::array<Point<T>, 6> sorted_right_angles;

    for (int i = 0; i < 6; i++) {
        sorted_angles[i] = get_point(i);
        sorted_right_angles[i] = right.get_point(i);
    }

    std::sort(sorted_angles.begin(), sorted_angles.end());
    std::sort(sorted_right_angles.begin(), sorted_right_angles.end());

    return sorted_angles == sorted_right_angles;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& f){
    os << "Hexagon's coordinates:"<< std::endl;
    for(size_t i = 0; i < 6; ++i){
        os << f.angles[i] << std::endl;
    }
    return os;

}

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T>& f){
    std::cout << "|Enter Hexagon's coordinates|" << std::endl;
    for(size_t i = 0; i < 6; ++i){
        is >> f.angles[i];
        if (is.fail()) {
            throw std::invalid_argument("Input must be a number");
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (f.angles[i] == f.angles[j]) {
                throw std::logic_error("Same coordinates for different angles");
            }
        }
    }
    f.size_ = 6;
    return is;
}

template <class T>
Hexagon<T>::operator double() const{
    return area();
}

template <class T>
size_t Hexagon<T>::size() const{
    return size_;
}

template <class T>
Point<T> Hexagon<T>::get_point(const int i) const{
    if ( i < 0 || i > 5){
        throw std::invalid_argument("Out of index range");
    }
    return angles[i];
}