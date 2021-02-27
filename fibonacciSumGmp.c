#include <stdio.h>
#include <gmp.h>

char* fibonacciSum(int index) {
    mpz_t sum;
    mpz_init(sum);
    mpz_set_ui(sum, 0);

    for ( int i = 0; i <= index; i++ ) {
        mpz_t element;
        mpz_init(element);
        mpz_fib_ui(element, i);
        mpz_add(sum, sum, element);
        mpz_clear(element);
    }

    char* answer = mpz_get_str(NULL, 10, sum);
    mpz_clear(sum);

    return answer;
}

int main() {
    int index;

    scanf("%d", &index);

    printf("%s\n", fibonacciSum(index));

    return 0;
}
