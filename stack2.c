#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
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
	
	printf("%d\n", stk.size);
	printf("%d %d\n", pop(&stk), stk.size);
	resize(5, &stk);
	printf("%d\n", stk.capacity);
}