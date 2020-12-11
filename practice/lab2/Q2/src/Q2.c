/*
 ============================================================================
 Name        : Q2.c
 Author      : Philip Okanlawon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addVec(int* C, int* A, int* B, int size);

int main(void) {
	clock_t t;
	int len = 50000000;
	int* A = calloc(len, sizeof(int));
	int* B = calloc(len, sizeof(int));
	int* C = calloc(len, sizeof(int));

	addVec(C, A, B, len);
	int sum = 0;
	int i;
	for (i=0; i<len; i++)
		sum += C[i];

	if (A == NULL || B == NULL || C == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}
	for (i=0; i<10; i++)
		printf("%d ", C[i]);

	t = clock();
	printf("\nExecution time: %.2f ms", ((float)t)/CLOCKS_PER_SEC*1000);

	free(A);
	free(B);
	free(C);
	exit (EXIT_SUCCESS);
}

void addVec(int* C, int* A, int* B, int size){
	int i;
	for (i=0; i<size; i++){
		C[i] = A[i] + B[i];
	}
}

/*
 * Sample run 1 with 50 million integers: (successful)
 * 0 0 0 0 0 0 0 0 0 0
 * Execution time: 457.00 ms
 */
