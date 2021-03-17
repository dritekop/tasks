#include <stdio.h>
#include "fibonacciSumGmp.h"

int main() {
    FILE* test;
    test = fopen("test.txt", "a");

    fprintf(test, "Sum of first 1345 elements:\n%s\n", fibonacciSum(1345));

    fclose(test);

    return 0;
}
