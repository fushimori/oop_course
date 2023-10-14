#pragma once

template<class T>
class Vector
{
public:
    Vector();
    bool is_empty() const;
    void resize(int new_size);
    int size() const;
    void push_back(const T& value);
    void pop_back();
    void set(int ind, const T& val);
    const T& get(int ind) const;

    ~Vector();

private:
    T* buf;
    int size_;
    int cap;
    int head;
};

template<class T>
Vector<T>::Vector() : buf(nullptr), size_(0), cap(0), head(0)
{
}

template<class T>
bool Vector<T>::is_empty() const
{
    return size_ == 0;
}

template<class T>
void Vector<T>::resize(int new_size)
{
    T* tmp = new T[new_size];
    for (int i = 0; i < size_; i++) {
        int ind = (head + i) % cap;
        tmp[i] = buf[ind];
    }
    delete [] buf;
    buf = tmp;
    cap = new_size;
    head = 0;
}

template<class T>
int Vector<T>::size() const
{ 
    return size_;
}

template<class T>
void Vector<T>::push_back(const T& value)
{
    if (size_ == cap) {
        resize(cap * 2);
    }
    int ind = (head + size_) % cap;
    buf[ind] = value;
    size_++;
}

template<class T>
void Vector<T>::pop_back()
{
    if (size_ > 0) {
        size_--;
        if (size_ <= cap / 3) {
            resize(cap * 3/5);
        }
    }
}

template<class T>
void Vector<T>::set(int ind, const T& val)
{
    if (ind >= 0 && ind < size_) {
        int real_ind = (head + ind) % cap;
        buf[real_ind] = val;
    }
}

template<class T>
const T& Vector<T>::get(int ind) const
{
    if (ind >= 0 && ind < size_) {
        int real_ind = (head + ind) % cap;
        return buf[real_ind];
    }
    throw std::out_of_range("Index is out of range");
}

template<class T>
Vector<T>::~Vector()
{
    size_ = 0;
    cap = 0;
    head = 0;
    delete [] buf;
    buf = nullptr;
}