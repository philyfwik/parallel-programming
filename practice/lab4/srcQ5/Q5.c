/*
 ============================================================================
 Name        : Q5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void count_sort(int a[], int n);
void par_count_sort(int a[], int n);
int main () {
	int a[10000];
	int n = sizeof(a)/sizeof(a[0]);
	printf("Array of size %d\n", n);

	//initialize a array
	for (int i=0; i<n; i++){
		if (i%2 == 0)
			a[i] = i+5;
		else
			a[i] = i+1;
	}

	double t = omp_get_wtime();
	count_sort(a, n);
	t = 1000 * (omp_get_wtime() - t);
	printf("Serially finished count sort in %.2f ms.\n", t);
	printf("First 5 numbers are [%d, %d, %d, %d, %d]\n", a[0], a[1], a[2], a[3], a[4]);

	double t2 = omp_get_wtime();
	par_count_sort(a, n);
	t2 = 1000 * (omp_get_wtime() - t2);
	printf("Parallel finished count sort with 8 threads in %.2f ms.\n", t2);
	printf("First 5 numbers are [%d, %d, %d, %d, %d]", a[0], a[1], a[2], a[3], a[4]);

 return 0;
}
void count_sort(int a[], int n) {
	int i, j, count;
	int* temp = malloc(n * sizeof(int));
	for (i = 0; i < n; i++){
		//count all elements < a[i]
		count = 0;
		for (j = 0; j < n; j++)
			if(a[j]<a[i] ||(a[j]==a[i] && j<i))
				count++;
		//place a[i] at right order
		temp[count] = a[i];
	}
	memcpy(a, temp, n * sizeof(int));
	free(temp);
}
void par_count_sort(int a[], int n) {
	int i, j, count;
	int* temp = malloc(n * sizeof(int));
#pragma omp parallel for private(j, count) num_threads(8)
	for (i = 0; i < n; i++){
		//count all elements < a[i]
		count = 0;
		for (j = 0; j < n; j++)
			if(a[j]<a[i] ||(a[j]==a[i] && j<i))
				count++;
		//place a[i] at right order
		temp[count] = a[i];
	}
	memcpy(a, temp, n * sizeof(int));
	free(temp);
}
/*
 * ---------------SERIAL------------------
 *Array of size 10000
 *Serially finished count sort in 293.00 ms.
 *First 5 numbers are [2, 4, 5, 6, 7]
 *Parallel finished count sort with 9 threads in 79.00 ms.
 *First 5 numbers are [2, 4, 5, 6, 7]
 */


