/*
 ============================================================================
 Name        : Q.c
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

int main(void) {
	clock_t t;
	int len = 10;
	int* A = malloc(len*sizeof(int));
	int* B = malloc(len*sizeof(int));
	int* C = malloc(len*sizeof(int));

	int i;
	for (i=0; i<len; i++){
		A[i] = i*3;
		B[i] = -i*3;
		C[i] = A[i]+B[i];
	}
	int sum = 0;
	for (i=0; i<len; i++)
		sum += C[i];

	if (A == NULL || B == NULL || C == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	printf("Sum: %d\n", sum);

	t = clock();
	printf("Execution time: %f sec", ((float)t)/CLOCKS_PER_SEC);

	free(A);
	free(B);
	free(C);
	exit (EXIT_SUCCESS);
}
/*
 * Sample 1 using 1 integer: (successful)
 * 			Sum: 0
 * 			Execution time: 0.000000 sec
 * Sample 2 using 10: (successful)
 * 			Sum: 0
 * 			Execution time: 0.000000 sec
 * Sample 3 using 50: (successful)
 *  		Sum: 0
 * 			Execution time: 0.002000 sec
 * Sample 4 using 100 million: (successful)
 *  		Sum: 0
 * 			Execution time: 1.033000 sec
 * Sample 5 using 1 trillion: (unsuccessful)
 * 			Not enough memory
 */
