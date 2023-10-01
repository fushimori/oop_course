#pragma once

#include <string>
#include <iostream>

class Twelve
{
public:
    Twelve();
    Twelve(const size_t &n, unsigned char t = '0');
    Twelve(const std::initializer_list< unsigned char> &t);
    Twelve(const std::string &t);
    Twelve(const Twelve & other);
    Twelve(Twelve && other) noexcept;

    bool   equals(const Twelve & other);
    bool   greater(const Twelve & other);
    bool   less(const Twelve & other);
    Twelve add(Twelve & other);
    Twelve subtract(Twelve & other);
    std::ostream&   print(std::ostream& os);

    size_t         get_size(); // getter
    unsigned char* get_arr(); // getter

    virtual ~Twelve() noexcept;

private:
    size_t size;
    unsigned char* array;

    void append(const size_t &k, unsigned char t);
    void erase(const size_t &k);
    void null_clear();
};