#pragma once

#include <iostream>
#include <vector>
#include <memory>

template <typename T, size_t Block_size>
class MyAllocator {
public:
    template <typename U>
    struct rebind {
        using other = MyAllocator<U, Block_size>;
    };
    
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = size_t;
    
    MyAllocator() noexcept {}
    ~MyAllocator() noexcept {}

    template <typename U>
    MyAllocator(const MyAllocator<U, Block_size>&) noexcept {}

    pointer allocate(size_type n) {
        if (n != 1)
            throw std::bad_alloc();
        if (pos == nullptr || static_cast<size_type>(end - pos) < n){
            data_.push_back(new value_type[Block_size]);
            pos = data_.back();
            end = pos + Block_size;
        }
        auto p = pos;
        pos += n;
        return p;
    }

    void deallocate(pointer p, size_type n) {
        if (n != 1) return;
        if (p == pos - n) {
            pos -= n;
            return;
        }
        auto it = std::find(data_.begin(), data_.end(), p);
        if (it != data_.end()) {
            delete[] *it;
            data_.erase(it);
        }
    }

    template <typename U, typename... Args>
    void construct(U *p, Args &&...args){
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

private:
    std::vector<pointer> data_;
    pointer pos = nullptr;
    pointer end = nullptr;
};
