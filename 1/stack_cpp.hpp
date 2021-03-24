#pragma once

#include <iostream>
#include <stdlib.h>
#include <memory>
#include <utility>

template <typename T>
class Stack {
    size_t Size;
    size_t Capacity;
    std::unique_ptr<T[]> values;

public:
    Stack(size_t size, T* arr) {
        this->Size = size;
        this->Capacity = size;
        this->values = std::make_unique<T[]>(this->Size);
        for (size_t i = 0; i < this->Size; i++) {
            this->values[i] = arr[i];
        }
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
        
        std::unique_ptr<T[]> temp = std::make_unique<T[]>(this->Size);
        temp = std::move(this->values);

        this->values = std::make_unique<T[]>(this->Size);
        this->values = std::move(temp);
    }

    Stack operator=(const Stack& stk) = delete;
};
