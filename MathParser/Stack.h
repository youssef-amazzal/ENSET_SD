#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
    T* elements;
    int topIndex;
    int capacity;

    void resize() {
        T* newElements = new T[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity *= 2;
    }

public:
    explicit Stack(int capacity = 100) : capacity(capacity) {
        elements = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] elements;
    }

    void push(T const& element) {
        if (topIndex >= capacity - 1) {
            resize();
        }
        elements[++topIndex] = element;
    }

    void pop() {
        if (topIndex < 0) {
            throw std::out_of_range("Empty stack");
        }
        --topIndex;
    }

    T top() {
        if (topIndex < 0) {
            throw std::out_of_range("Empty stack");
        }
        return elements[topIndex];
    }

    bool empty() {
        return topIndex < 0;
    }
};
