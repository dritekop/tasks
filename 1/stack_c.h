#pragma once

#include <stdio.h>
#include <stdlib.h>

struct stack {
    size_t size;
    size_t capacity;
    int* elements;
};

struct stack create(size_t size, size_t capacity, int* x) {
    struct stack stk;
    stk.size = size;
    stk.capacity = capacity;
    stk.elements = x;
    
    return stk;
}

void push(int x, struct stack* stk) {    
    if ( stk->capacity + 1 > stk->size ) {
        printf("No space in the stack. Resize it.\n");
        return;
    }

    stk->capacity += 1;
    int index = stk->capacity - 1;
    *(stk->elements + index) = x;
}

int pop(struct stack* stk) {
    if ( stk->size == 0 || stk->capacity == 0 ) {
        printf("Empty or non-existing stack\n");
        exit(EXIT_FAILURE);
    }
    stk->capacity -= 1;
    int element = stk->elements[stk->capacity];
    
    return element;
}

size_t size(struct stack* stk) {
    return stk->size;
}

size_t capacity(struct stack* stk) {
    return stk->capacity;
}

void Resize(int x, struct stack* stk) {
    if ( (int)stk->size + x <= 0 ) {
        printf("Invalid resize parameter\n");
        exit(EXIT_FAILURE);
    }
    
    stk->size += x;
    if ( stk->size < stk->capacity ) {
        stk->capacity = stk->size;
    }
}
