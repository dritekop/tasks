#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    void* ptr;
	int top;
	int size;
};

struct stack create(int x) {
    struct stack stk;
    stk.ptr = malloc(sizeof(int)*x);
    stk.size = x;
    
    return stk;
}

void push(int x, struct stack* stk) {
	stk->size += 1;
	stk->top = x;
	stk->ptr = realloc(stk->ptr, sizeof(int)*stk->size);	
}

int main() {
	struct stack stk = create(5);
	printf("%d\n", stk.size);
	push(4, &stk);
	printf("%d %d\n", stk.top, stk.size);
}
