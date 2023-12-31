#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <algorithm>
#include "point.h"

class Figure
{

public:
    Figure() = default;

    virtual double area() const = 0;
    virtual Point center() const = 0;
    virtual operator double() const = 0;
    
    virtual ~Figure() = default;
};