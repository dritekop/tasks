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

int main() {
    int array[3] = { 10, 8, 7 };
    int length = sizeof(array)/sizeof(int);
    
    struct stack stk = create(length, length, array);
    
    printf("%zu - stk.size %zu - stk.capacity\n", size(&stk), capacity(&stk));

    Resize(-1, &stk);
    printf("%zu - stk.size %zu - stk.capacity : after resize(-1, &stk)\n", size(&stk), capacity(&stk));
    
    Resize(5, &stk);
    printf("%zu - stk.size %zu - stk.capacity : after resize(5, &stk)\n", size(&stk), capacity(&stk));
    
    push(123, &stk);
    printf("push(123, &stk)\n");
    
    for ( int i = stk.capacity; i != 0; i-- ) {
        size_t a = capacity(&stk);
        int b = pop(&stk);
        size_t c = capacity(&stk);
        size_t d = size(&stk);
        printf("%zu - capacity(&stk) before pop, %d - pop(&stk), %zu - capacity(&stk) after pop, %zu - size(&stk)\n", a, b, c, d);
    }
    printf("%zu - stk.size %zu - stk.capacity\n", stk.size, stk.capacity);

    return 0;
}
