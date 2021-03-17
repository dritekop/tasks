#include <stdio.h>
#include "fibonacciSum.h"

int main() {
    FILE* test = fopen("test.txt", "w");

    fprintf(test, "Sum of first 20 elements:\n%d\n", fibonacciSum(20));

    fclose(test);
}
