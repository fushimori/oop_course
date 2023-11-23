#pragma once

#include <iostream>
#include <memory>
#include "allocator.h"

template <typename T, size_t Block_size, typename Allocator = MyAllocator<T, Block_size>>
class MyForwardList{

private:
    struct Node {
        T value;
        Node* next;
    };

public:
    class MyIterator
    {

    public:
        using iterator_category = std::forward_iterator_tag;
        using reference = T&;
        using pointer = T*;
        using value_type = T;

        MyIterator(Node* ptr_): ptr(ptr_) {};

        reference operator*() const {
            return ptr->value;
        }

        pointer operator->() const {
            return &(ptr->value);
        }

        MyIterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        MyIterator operator++(int) {
            MyIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const MyIterator& rhs) const {
            return ptr == rhs.ptr;
        }

        bool operator!=(const MyIterator& rhs) const {
            return !(*this == rhs);
        }

        ~MyIterator() {};
        
    private:
        Node* ptr;
    };
public:
    using iterator = MyIterator;
    using const_iterator = MyIterator;
    using allocator_type = Allocator;

    MyForwardList(): head(nullptr) {};

    ~MyForwardList() {
        clear();
    };

    T front() {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }
        return head->value;
    }

    void push_front(const T& value) {
        using NodeAllocator = typename Allocator::template rebind<Node>::other;
        typename NodeAllocator::pointer newNode = NodeAllocator().allocate(1);
        allocator.construct(&(newNode->value), value);
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* tmp = head;
        head = head->next;
        allocator.destroy(tmp);
        allocator.deallocate(tmp, 1);
    }

    bool empty() const {
        return head == nullptr;
    }

    void clear() {
        using NodeAllocator = typename Allocator::template rebind<Node>::other;
        Node* current = head;
        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            allocator.destroy(&(tmp->value));
            NodeAllocator().deallocate(tmp, 1);
        }
        head = nullptr;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator begin() const {
        return const_iterator(head);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

private:
    Node* head;
    allocator_type allocator;
};
