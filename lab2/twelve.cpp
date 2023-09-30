#include "include.h"

int char_to_digit(const unsigned char c){
    if( 'B' >= c and c >= 'A'){
        return 10 + c - 'A';
    }
    else if('0' <= c and c <= '9'){
        return c - '0';
    }
    else{
        std::cout << c << std::endl;
        throw std::invalid_argument("char to digit Value must be within number system");
    }
}

unsigned char digit_to_char(int dg){
    if( 0 <= dg and dg <= 9){
        return  dg + '0';
    }
    else{
        return dg - 10 + 'A';
    }
}



Twelve::Twelve() : size{0}, array{nullptr} {}; 

Twelve::Twelve(const size_t &n, unsigned char t)
{
    array = new unsigned char[n];
    for(size_t i = 0; i < n; i++){
        array[i] = t;
    }
    size = n;
}

Twelve::Twelve(const std::initializer_list<unsigned char> &t)
{   
    for(auto &c : t){
        if( (c < '0' or c > '9' ) and (c < 'A' or c > 'B')){
            throw std::invalid_argument("Value must be within number system");
        }
    }

    array = new unsigned char[t.size()];
    size = t.size();
    size_t i{size};
    for(auto &c : t){
        array[--i] = c;
    }
    
}

Twelve::Twelve(const std::string &t)
{
    for(auto &c : t){
        if( (c < '0' or c > '9' ) and (c < 'A' or c > 'B')){
            throw std::invalid_argument("Value must be within number system");
        }
    }
    size = t.size();
    array = new unsigned char[size];
    for(size_t i{0}; i < size; i++){
        array[i] = t[size - 1 - i];
    }
}


Twelve::Twelve(Twelve && other) noexcept
{
    array = other.array;
    size = other.size;

    other.array = nullptr;
    other.size = 0;
}


bool Twelve::equals(const Twelve & other){
    if(size==other.size){
        for(size_t i{0}; i < size; i++){
            if(array[i] != other.array[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}
bool Twelve::greater(const Twelve &other){
    if(size==other.size){
        for(size_t i{0}; i < size; i++){
            if(array[size - 1 - i] == other.array[size - 1 - i]){
                continue;
            }
            else{
                return array[size - 1 - i] > other.array[size - 1 - i];
            }
        }
        return false;
    }
    else{
        return size > other.size;
    }
}
bool Twelve::less(const Twelve &other){
    if(size==other.size){
        for(size_t i{0}; i < size; i++){
            if(array[size - 1 - i] == other.array[size - 1 - i]){
                continue;
            }
            else{
                return array[size - 1 - i] < other.array[size - 1 - i];
            }
        }
        return false;
    }
    else{
        return size < other.size;
    }
}

void Twelve::append(const size_t &k, unsigned char t){
    size_t n_size = size+k;
    unsigned char* n_array = new unsigned char[n_size];
    std::move(array, array + size, n_array);
    for(size_t i{size}; i < n_size; i++){
        n_array[i] = t;
    }

    array = n_array;
    size = n_size;

}

void Twelve::add(Twelve & other){
    if(size == other.size){
        std::cout << "size " << size << std::endl;
        int carry = 0;
        for(size_t i{0}; i < size;  i++){
            int sum = char_to_digit(array[i]) + char_to_digit(other.array[i]) + carry;
            std::cout << sum%12 << std::endl;
            array[i] = digit_to_char(sum%12);
            carry = sum / 12;
        }
        if(carry > 0){
            this->append(1,digit_to_char(carry));
        }
    }
    else{
        //throw std::invalid_argument("Sizes must be equal");
        if(this->greater(other)){
            other.append(size - other.size, '0');
            std::cout << "gt_add" << std::endl;
            return add(other);
        }
        else{
            this->append(other.size - size, '0');
            std::cout << "ls_add" << std::endl;
            return add(other);

        }
    }
}

Twelve Twelve::subtract(Twelve & other){
    throw std::invalid_argument("subtract");
}

std::ostream&   Twelve::print(std::ostream& os){
    for(size_t i{0}; i < size; i++){
        os << array[size - 1 - i];
    }
    return os;
}

Twelve::~Twelve() noexcept
{
    size = 0;
    delete[] array;
    array = nullptr;

}