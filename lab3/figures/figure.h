#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "point.h"

class Figure
{

public:
    Figure(){};

    virtual double area() const = 0;
    virtual Point center() const = 0;
    
    virtual ~Figure(){};
    
};