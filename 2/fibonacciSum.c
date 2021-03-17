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
    FILE* test = fopen("test.txt", "w");

    fprintf(test, "Sum of first 20 elements:\n%d\n", fibonacciSum(20));

    fclose(test);
}
