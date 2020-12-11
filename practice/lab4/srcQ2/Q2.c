/*
 ============================================================================
 Name        : Q2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define NRA 10 //number of rows in A
#define NCA 5 //number of columns in A = number of rows in B
#define NCB 20 //number of columns in B
/**
 * Hello OpenMP World prints the number of threads and the current thread id
 */
int main (int argc, char *argv[]) {

	int A[10][5];
	int B[5][20];
	int C[10][20];

	int i,j;

#pragma omp parallel
	{
		#pragma omp for private(j)
		for (i=0; i<NRA; i++){
			for (j=0; j<NCA; j++){
				A[i][j] = i+j;
			}
		}
#pragma omp barrier
		#pragma omp for private(j)
		for (i=0; i<NCA; i++){
			for (j=0; j<NCB; j++){
				B[i][j] = i*j+1;
			}
		}
#pragma omp barrier
        #pragma omp for private(j)
		for (i=0; i<NRA; i++){
			for (j=0; j<NCB; j++){
				C[i][j] = 0;
				int k;
				for (k=0; k<5; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	for (i=0; i<NRA; i++){
		for (j=0; j<NCB; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}

 return 0;
}


