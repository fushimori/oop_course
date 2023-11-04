#pragma once

#include <iostream>
#include <string>

class Point
{

    friend Point operator+(const Point& left, const Point& right);
    friend Point operator-(const Point& left, const Point& right);
    friend bool operator==(const Point& left, const Point& right);
    friend bool operator!=(const Point& left, const Point& right);
    friend bool operator>(const Point& left, const Point& right);
    friend bool operator<(const Point& left, const Point& right);
    friend bool operator>=(const Point& left, const Point& right);
    friend bool operator<=(const Point& left, const Point& right);

    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    
    Point& operator=(const Point& right);
    

    double x_{};
    double y_{};
};