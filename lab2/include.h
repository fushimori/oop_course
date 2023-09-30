#pragma once

#include <string>
#include <iostream>

class Twelve
{
public:
    Twelve();
    Twelve(const size_t &n, unsigned char t = 0);
    Twelve(const std::initializer_list< unsigned char> &t);
    Twelve(const std::string &t);
    Twelve(Twelve && other) noexcept;

    bool   equals(const Twelve & other);
    bool   greater(const Twelve & other);
    bool   less(const Twelve & other);
    void   add(Twelve & other);
    Twelve subtract(Twelve & other);
    std::ostream&   print(std::ostream& os);

    virtual ~Twelve() noexcept;

private:
    size_t size;
    unsigned char* array;

    void append(const size_t &k, unsigned char t);
};