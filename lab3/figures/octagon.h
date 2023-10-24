#pragma once

#include "figure.h"
#include <iostream>

class Octagon : public Figure
{

    friend std::ostream& operator<<(std::ostream& os, const Octagon& f);
    friend std::istream& operator>>(std::istream& is, Octagon& f);

public:
    Octagon();
    Octagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6, Point& p7, Point& p8);

    virtual double area() const override;
    virtual Point  center() const override;

    Point  get_point(const int i) const;
    size_t size() const;

    Octagon& operator=(const Octagon& right);
    Octagon& operator=(Octagon&& right);
    bool     operator==(const Octagon& right) ;
    virtual  operator double() const override;



    ~Octagon(){};

private:
    Point angles[8];
    size_t size_;
};
