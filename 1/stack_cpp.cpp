#include "stack_cpp.hpp"
#include <fstream>

int main() {
    std::ofstream test;

    int x[] = { 9, 6, 7 };
    Stack<int> st(3, x);

    
    test.open("test.txt", std::ios_base::app);
    test << "The C++ language:" << std::endl;
    test << "Stack st (9, 6, 7)" << std::endl;
    st.push(12);
    test << "st.push(12) writes in terminal \"There is no place in the stack. Resize it.\"" 
    << std::endl;
    for ( int i = st.capacity(); i != 0; i-- ) {
        size_t a = st.capacity();
        int b = st.pop();
        size_t c = st.capacity();
        test << a << " - st.capacity(), " << b << " - st.pop(), " 
        << c << " - st.capacity()" << std::endl;
    }
    st.push(65);
    test << "st.push(65);" << std::endl;
    size_t a = st.capacity();
    int b = st.pop();
    size_t c = st.capacity();
    
    test << a << " - st.capacity(), " << b << " - st.pop(), " <<
    c  << " - st.capacity()" << std::endl;
    
    test << st.capacity() << " - st.capacity(), " << st.size() <<
    " - st.size()" << std::endl;

    // st.Resize(-12);
    // st.pop();
    st.Resize(6);
    test << st.capacity() << " - st.capacity(), " << st.size() <<
    " - st.size() afrer st.Resize(6)" << std::endl;

    test.close();
}
