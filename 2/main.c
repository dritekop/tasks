#include <stdio.h>
#include "fibonacciSum.h"
#include "fibonacciSumGmp.h"

int main() {
    int index1;
    int index2;

    printf("Note that the values of the elements of this sequence have extremely high growing speed.\n\
Follow the instructions and type only digits or be ready for an unexpected results.\n");
    printf("Please type the index of a number from the Fibonacci sequence to calculate the sum of elements (only positive value): ");
    scanf("%d", &index1);
    printf("%s\n", fibonacciSumGmp(index1));

    printf("Please type the index of a number from the Fibonacci sequence to calculate the sum of elements (modulos less than or equal to 44,\
 if you don't want to have an integer overflow) and wait...: ");
    scanf("%d", &index2);
    printf("%d\n", fibonacciSum(index2));

    return 0;
}
