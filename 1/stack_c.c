#include "stack_c.h"

int main() {
    FILE* test = fopen("test.txt", "w");

    int array[3] = { 10, 8, 7 };
    int length = sizeof(array)/sizeof(int);
    
    stack stk = create(length, length, array);

    fprintf(test, "The C language:\n");
    fprintf(test, "%zu - stk.size %zu - stk.capacity\n", size(&stk), capacity(&stk));

    Resize(-1, &stk);
    fprintf(test, "%zu - stk.size %zu - stk.capacity : after resize(-1, &stk)\n", size(&stk), capacity(&stk));
    
    Resize(5, &stk);
    fprintf(test, "%zu - stk.size %zu - stk.capacity : after resize(5, &stk)\n", size(&stk), capacity(&stk));
    
    push(123, &stk);
    fprintf(test, "push(123, &stk)\n");
    
    for ( int i = stk.capacity; i != 0; i-- ) {
        size_t a = capacity(&stk);
        int b = pop(&stk);
        size_t c = capacity(&stk);
        size_t d = size(&stk);
        fprintf(test, "%zu - capacity(&stk) before pop, %d - pop(&stk), %zu - capacity(&stk) after pop, %zu - size(&stk)\n", a, b, c, d);
    }
    fprintf(test, "%zu - stk.size %zu - stk.capacity\n", stk.size, stk.capacity);

    fclose(test);

    return 0;
}
