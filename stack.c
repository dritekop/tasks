#include <stdio.h>
#include <stdlib.h>

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
		stk->elements = realloc(stk->elements, sizeof(int)*(stk->size + 1));
	}
	*(stk->elements + index) = x;
}

int pop(struct stack* stk) {
	int index = stk->size - 1;
	int element = stk->elements[index];
	
	return element;
}

void resize(int x, struct stack* stk) {
	stk->capacity += x;
}

int main() {
	int array[3] = { 10, 8, 7 };
	
	struct stack stk = create(3, array);
	
	printf("%d - stk.size %d - stk.capacity\n", stk.size, stk.capacity);
	// printf("%d - pop(&stk), %d - stk.size\n", pop(&stk), stk.size);
	resize(5, &stk);
	printf("% d - stk.size %d - stk.capacity : after resize(5, &stk)\n", stk.size, stk.capacity);
	push(123, &stk);
	// printf("%d - pop(&stk), %d - stk.size, %d - stk.capacity\n", pop(&stk), stk.size, stk.capacity);
	for ( ; stk.size != 0; stk.size -- ) {
		printf("%d - pop(&stk), %d element\n", pop(&stk), stk.size);
	}
	printf("%d - stk.size %d - stk.capacity\n", stk.size, stk.capacity);
}
