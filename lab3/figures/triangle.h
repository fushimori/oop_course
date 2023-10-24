#pragma once

#include "figure.h"
#include <iostream>

class Triangle : public Figure
{

    friend std::ostream& operator<<(std::ostream& os, const Triangle& f);
    friend std::istream& operator>>(std::istream& is, Triangle& f);

public:
    Triangle();
    Triangle(Point& p1, Point& p2, Point& p3);

    virtual double area() const override;
    virtual Point  center() const override;

    Point  get_point(const int i) const;
    size_t size() const;

    Triangle& operator=(const Triangle& right);
    Triangle& operator=(Triangle&& right);
    bool      operator==(const Triangle& right);
    virtual   operator double() const override;

    


    ~Triangle(){};

private:
    Point angles[3];
    size_t size_;
};


