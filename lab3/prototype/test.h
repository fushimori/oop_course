#pragma once

#include <iostream>
#include <string>

class Figure
{
public:
    Figure();

    virtual double area() const = 0;

    ~Figure();
    
};