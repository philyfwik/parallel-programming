/*
 ============================================================================
 Name        : Q5.c
 Author      : Philip Okanlawon
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* vecCreate (int size);
int* vecCreateOpenMP(int size, int num_thread);

int main (int argc, char *argv[]) {
	clock_t t;
	int size = 50000000;
	int* A = vecCreate(size);
	printf("Using serial code \nv[%d] = %d\n", A[49999999], A[49999999]);
	t = clock();
	printf("Time: %.2f ms\n", ((float)t)/CLOCKS_PER_SEC*1000);

	int threads = 4;
	int* B = vecCreateOpenMP(size, threads);
	printf("\nUsing OpenMP with %d threads:\nv[%d] = %d\n", threads, B[49999999], B[49999999]);
	t = clock()-t;
	printf("Time: %.2f ms", ((float)t)/CLOCKS_PER_SEC*1000);

	return 0;
}

int* vecCreate(int size){
	int* A = malloc(size*sizeof(int));
	if (A == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}
	int i;
	for (i=0; i<size; i++)
		A[i] = i;

	return A;
}
int* vecCreateOpenMP(int size, int num_thread){
	int* A = malloc(size*sizeof(int));
	if (A == NULL){
		fprintf(stderr, "Not enough memory\n");
		exit(EXIT_FAILURE);
	}

	// check if divisible
	if (size % num_thread != 0){
		printf("Error: number of threads must be divisible by vector size");
		exit(EXIT_FAILURE);
	}

	// get subsize
	int subsize = size/num_thread;

   #pragma omp parallel num_threads(num_thread)
	{

		// get thread id (tid)
		int tid = omp_get_thread_num();
		int first = tid*subsize;
		int last = (tid+1)*subsize;
		//printf("T%d will process range [%d,%d]\n", tid, first, last);
		for (int i=first; i<last; i++) 	A[i] = i;
	}
	return A;
}
/*
 * Using serial code
 * v[49999999] = 49999999
 * Time: 141.00 ms
 *
 * Using OpenMP with 4 threads:
 * v[49999999] = 49999999
 * Time: 52.00 ms
 */
