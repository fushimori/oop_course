#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <algorithm>
#include "point.h"


template <Number T>
class Figure {
public:

    Figure() = default;

    virtual T area() const = 0;
    virtual Point<T> center() const = 0;
    virtual operator double() const = 0;
    
    virtual ~Figure() = default;
};