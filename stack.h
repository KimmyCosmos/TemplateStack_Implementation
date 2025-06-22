#ifndef STACK_H
#define STACK_H

#include <stdexcept>

// Lab 4: Template Stack
// Name: [Your Name]
// CS010C - Spring 2025
// Implements a basic stack using a template class and fixed-size array

const int MAX_SIZE = 20;

template <typename T>
class stack {
private:
    T data[MAX_SIZE];  // Array to store stack elements
    int size;          // Tracks number of elements in the stack

public:
    // Constructor initializes an empty stack
    stack() : size(0) {}

    // Pushes a new element onto the stack
    void push(T val) {
        if (size >= MAX_SIZE) {
            throw std::overflow_error("Called push on full stack.");
        }
        data[size++] = val;
    }

    // Pops the top element off the stack
    void pop() {
        if (size == 0) {
            throw std::out_of_range("Called pop on empty stack.");
        }
        --size;
    }

    // Pops the top two elements off the stack
    void pop_two() {
        if (size == 0) {
            throw std::out_of_range("Called pop_two on empty stack.");
        }
        if (size == 1) {
            throw std::out_of_range("Called pop_two on a stack of size 1.");
        }
        size -= 2;
    }

    // Returns the top element on the stack
    T top() const {
        if (size == 0) {
            throw std::underflow_error("Called top on empty stack.");
        }
        return data[size - 1];
    }

    // Checks if the stack is empty
    bool empty() const {
        return size == 0;
    }
};

#endif
