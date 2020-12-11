/*
 ============================================================================
 Name        : Q3.c
 Author      : Philip Okanlawon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 **Results at bottom of page**
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* addVec2(int* A, int* B, int size);

int main(void) {
	clock_t t;
	int len = 100000000;
	int* A = malloc(len*sizeof(int));
	int* B = malloc(len*sizeof(int));

	int i;
	for (i=0; i<len; i++){
		A[i] = i*3;
		B[i] = -i*3;
	}

	int *C= addVec2(A, B, len);
	int sum=0;
	for (i=0; i<len; i++)
		sum += C[i];
	printf("Sum: %d\n", sum);

	if (A == NULL || B == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	t = clock();
	printf("Execution time: %f sec", ((float)t)/CLOCKS_PER_SEC);

	free(A);
	free(B);
	exit (EXIT_SUCCESS);
}

int* addVec2(int* A, int* B, int size){
	int* C = malloc(size*sizeof(int));

	int i;
	for (i=0; i<size; i++){
		C[i] = A[i]+B[i];
	}
	return C;
}
/*
 * Sample 1 using 100 million integers: (successful)
 * 			Sum: 0
 * 			Execution time: 1.176000 sec
*/
