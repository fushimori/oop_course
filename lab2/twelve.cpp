#include "include.h"

static int char_to_digit(const unsigned char c){
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

static unsigned char digit_to_char(int dg){
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
    if( (t < '0' or t > '9' ) and (t < 'A' or t > 'B')){
        throw std::invalid_argument("Value must be within number system");
    }
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
    this->null_clear();
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
    this->null_clear();
}

Twelve::Twelve(const Twelve & other)
{
    size  = other.size;
    array = new unsigned char[size];

    for(size_t i{0};i < size; i++){
        array[i] = other.array[i];
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

Twelve Twelve::add(Twelve & other)
{
    if(size == other.size){
        Twelve result(size);
        int carry = 0;
        for(size_t i{0}; i < size;  i++){
            int sum = char_to_digit(array[i]) + char_to_digit(other.array[i]) + carry;
            result.array[i] = digit_to_char(sum%12);
            carry = sum / 12;
        }
        if(carry > 0){
            result.append(1,digit_to_char(carry));
        }
        return result;
    }
    else{
        if(this->greater(other)){
            int dif = size - other.size;
            other.append(dif, '0');
            Twelve result(size);
            int carry = 0;
            for(size_t i{0}; i < size;  i++){
                int sum = char_to_digit(array[i]) + char_to_digit(other.array[i]) + carry;
                result.array[i] = digit_to_char(sum%12);
                carry = sum / 12;
            }
            if(carry > 0){
                result.append(1,digit_to_char(carry));
            }
            
            other.erase(dif);
            return result;
        }
        else{
            int dif = other.size - size;
            this->append(dif, '0');
            Twelve result(size);
            int carry = 0;
            for(size_t i{0}; i < size;  i++){
                int sum = char_to_digit(array[i]) + char_to_digit(other.array[i]) + carry;
                result.array[i] = digit_to_char(sum%12);
                carry = sum / 12;
            }
            if(carry > 0){
                result.append(1,digit_to_char(carry));
            }
            this->erase(dif);
            return result;
        }
    }
}

Twelve Twelve::subtract(Twelve & other)
{
    if(this->greater(other)){
        Twelve result(size);
        int dif = 0;
        if(size != other.size){
            dif = size - other.size;
            other.append(dif, '0');
        }
        int carry = 0;
        for(size_t i{0}; i < size;  i++){
            int sum = char_to_digit(array[i]) - char_to_digit(other.array[i]) - carry;
            if(sum < 0){
                result.array[i] = digit_to_char((12 + sum) % 12);
                carry = 1;
            }
            else{
                result.array[i] = digit_to_char(sum % 12);
                carry = 0;
            }
        }
        other.erase(dif);

        result.null_clear();
        return result;
    }
    else if(this->less(other)){
        throw std::logic_error("Minued must be large");
    }
    else{
        return Twelve(1);
    }
}

std::ostream&   Twelve::print(std::ostream& os)
{
    this->null_clear();
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

size_t Twelve::get_size()
{
    return size;
}
unsigned char* Twelve::get_arr()
{
    return array;
}

void Twelve::append(const size_t &k, unsigned char t)
{
    if(k <= 0){
        return;
    }
    size_t n_size = size+k;
    unsigned char* n_array = new unsigned char[n_size];
    std::move(array, array + n_size, n_array);
    for(size_t i{size}; i < n_size; i++){
        n_array[i] = t;
    }

    delete[] array;
    array = n_array;
    size = n_size;
}

void Twelve::erase(const size_t &k)
{
    if(k <= 0){
        return;
    }
    size_t n_size = size - k;
    unsigned char* n_array = new unsigned char[n_size];
    std::move(array, array + n_size, n_array);

    delete[] array;
    array = n_array;
    size = n_size;
}

void Twelve::null_clear()
{
    size_t cnt = 0;
    for(size_t i{this->size - 1}; i > 0; i--){
        if(this->array[i] != '0'){
            break;
        }
        cnt++;
    }
    this->erase(cnt);
}