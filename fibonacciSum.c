#include <stdio.h>

int fibonacciSum(int n) {
    if ( n == 1 ) {
        return 1;
    }
    if ( n > 0 ) {
        return (fibonacciSum(n-1) + fibonacciSum(n-2));
    }
    if ( n < 0 ) {
        return (fibonacciSum(n+2) - fibonacciSum(n+1));
    }
    return 0;
}

int main() {
    int index;

    scanf("%d", &index);

    index += 2;

    printf("%d", fibonacciSum(index) - 1);
}
