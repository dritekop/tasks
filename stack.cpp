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
        this->Capacity += 1;
        if ( this->Capacity > this->Size ) {
            this->Size = this->Capacity;
        }
        int index = this->Capacity - 1;
        this->values[index] = x;
    }

    T pop() {
        if ( this->Capacity == 0 || this->Size == 0 ) {
            exit(0);
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
            this->Size = 0;
            this->Capacity = 0;

            return; 
        }
        this->Size = newSize;
        this->Capacity = newSize;
    }

    Stack operator=(const Stack& stk) = delete;
};

template <typename T>
Stack<T> create(size_t size, T* array) {
    return Stack<T>(size, array);
}

int main() {
    int x[] = { 9, 6, 7 };
    Stack<int> st = create(3, x);
    std::cout << st.capacity() << " " << st.pop() << " " << st.capacity() << std::endl;
    st.push(65);
    std::cout << st.capacity() << " " << st.pop() << " " << st.capacity() << std::endl;
    std::cout << st.capacity() << " " << st.pop() << " " << st.capacity() << std::endl;
    st.Resize(-12);
    std::cout << st.capacity() << " " << st.size() << std::endl;
}
