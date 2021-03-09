#include <stdio.h>

struct stack {
	size_t size;
	size_t capacity;
	int* elements;
};

struct stack create(size_t size, int* x) {
	struct stack stk;
	stk.size = size;
	stk.capacity = size;
	stk.elements = x;
	
	return stk;
}

void push(int x, struct stack* stk) {
	stk->size += 1;
	int index = stk->size - 1;
	
	if ( stk->size > stk->capacity ) {
		stk->capacity = stk->size;
	}

	*(stk->elements + index) = x;
}

int pop(struct stack* stk) {
	stk->size -= 1;
	int element = stk->elements[stk->size];
	
	return element;
}

size_t size(struct stack* stk) {
	return stk->size;
}

size_t capacity(struct stack* stk) {
	return stk->capacity;
}

void Resize(int x, struct stack* stk) {
	if ( (int)stk->capacity + x <= 0 ) {
        stk->capacity = 0;
        stk->size = 0;
        return;
    }
    
	stk->capacity += x;
    
	if ( stk->capacity < stk->size ) {
        stk->size = stk->capacity;
    }
}

int main() {
	int array[3] = { 10, 8, 7 };
	int length = sizeof(array)/sizeof(int);
	
	struct stack stk = create(length, array);
	
	printf("%lu - stk.size %lu - stk.capacity\n", size(&stk), capacity(&stk));

	Resize(-1, &stk);
	printf("%lu - stk.size %lu - stk.capacity : after resize(-1, &stk)\n", size(&stk), capacity(&stk));
	
	Resize(5, &stk);
	printf("%lu - stk.size %lu - stk.capacity : after resize(5, &stk)\n", size(&stk), capacity(&stk));
	
	push(123, &stk);
	printf("push(123, &stk)\n");
	
	for ( int i = stk.size; i != 0; i-- ) {
		printf("%d - pop(&stk), %lu element\n", pop(&stk), size(&stk));
	}
	printf("%lu - stk.size %lu - stk.capacity\n", size(&stk), capacity(&stk));

	return 0;
}
