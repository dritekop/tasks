#pragma once

#include <iostream>
#include <stdlib.h>

template <typename T>
class Stack {
    T* values;
    size_t Size;
    size_t Capacity;

public:
    Stack(size_t size, T* array) {
        this->Size = size;
        this->Capacity = size;
        this->values = array;
    };

    ~Stack() {};

    void push(T x) {
        if ( this->Capacity + 1 > this->Size ) {
            std::cout << "There is no place in the stack. Resize it." << std::endl;

            return;
        }
        this->Capacity += 1;
        int index = this->Capacity - 1;
        this->values[index] = x;
    }

    T pop() {
        if ( this->Capacity == 0 || this->Size == 0 ) {
            std::cout << "The stack is empty." << std::endl;
            exit(EXIT_FAILURE);
        }
        this->Capacity -= 1;
        int index = this->Capacity;

        return this->values[index];
    }

    size_t capacity() {
        return this->Capacity;
    }

    size_t size() {
        return this->Size;
    }

    void Resize(int x) {
        int newSize = this->Size + x;
        if ( newSize <= 0 ) {
            std::cout << "Invalid resize paramater." << std::endl;
            exit(EXIT_FAILURE); 
        }
        this->Size = newSize;
    
    }

    Stack operator=(const Stack& stk) = delete;
};

template <typename T>
Stack<T> create(size_t size, T* array) {
    return Stack<T>(size, array);
}
