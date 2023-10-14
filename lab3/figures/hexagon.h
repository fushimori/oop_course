#pragma once

#include "figure.h"
#include <iostream>

class Hexagon : public Figure
{

    friend std::ostream& operator<<(std::ostream& os, const Hexagon& f);
    friend std::istream& operator>>(std::istream& is, Hexagon& f);

public:
    Hexagon();
    Hexagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6);

    virtual double area() const override;
    virtual Point center() const override;

    Point get_point(const int i) const;

    Hexagon& operator=(const Hexagon& right);
    Hexagon& operator=(Hexagon&& right);
    bool operator==(const Hexagon& right);



    ~Hexagon(){};

private:
    Point angles[6];
};

