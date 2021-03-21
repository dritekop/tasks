#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int* elements;
} stack;

stack create(size_t size, size_t capacity, int* x) {
    stack stk;
    stk.size = size;
    stk.capacity = size;

    stk.elements = (int*)calloc(stk.size, sizeof(int));
    if (!stk.elements) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < stk.size; i++) {
        stk.elements[i] = x[i];
    }
    
    return stk;
}

void push(int x, stack* stk) {    
    if ( stk->capacity + 1 > stk->size ) {
        printf("No space in the stack. Resize it.\n");
        return;
    }

    int index = stk->capacity;
    stk->capacity += 1;
    *(stk->elements + index) = x;
}

int pop(stack* stk) {
    if ( stk->size == 0 || stk->capacity == 0 ) {
        printf("Empty or non-existing stack\n");
        exit(EXIT_FAILURE);
    }
    stk->capacity -= 1;
    int element = stk->elements[stk->capacity];
    
    return element;
}

size_t size(stack* stk) {
    return stk->size;
}

size_t capacity(stack* stk) {
    return stk->capacity;
}

void Resize(int x, stack* stk) {
    if ( (int)stk->size + x <= 0 ) {
        free(stk->elements);
        printf("Stack was destroyed.\n");
        exit(EXIT_SUCCESS);
    }
    
    stk->size += x;
    
    if ( stk->capacity > stk->size ) {
        stk->capacity = stk->size;
    }
    
    int* temp = (int*)realloc(stk->elements, stk->size*sizeof(int*));
    if (temp) {
        stk->elements = temp;
    } else {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
}
