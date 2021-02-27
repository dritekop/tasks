#include <stdio.h>

int fibonacci(int n) {
    if ( n == 1 ) {
        return 1;
    }
    if ( n > 0 ) {
        return (fibonacci(n-1) + fibonacci(n-2));
    }
    if ( n < 0 ) {
        return (fibonacci(n+2) - fibonacci(n+1));
    }
    return 0;
}

int fibonacciSum(int n) {
    n += 2;
    return fibonacci(n) - 1;
}

int main() {
    int index;

    scanf("%d", &index);

    printf("%d", fibonacciSum(index));
}
