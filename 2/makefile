all: compile
	./fibonacciSum
	./fibonacciSumGmp
	./main

compile:
	gcc fibonacciSum.c -std=c99 -o fibonacciSum
	gcc fibonacciSumGmp.c -std=c99 -lgmp -o fibonacciSumGmp
	gcc main.c -std=c99 -lgmp -o main
