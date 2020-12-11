/*
 ============================================================================
 Name        : Q4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rand.h"

int main (int argc, char *argv[]) {

	int number_in_circle = 0;
	int toss, number_of_tosses;
	double pi_estimate;

	printf("How many random numbers?\n");
	scanf("%d", &number_of_tosses);

# pragma omp parallel reduction(+:number_in_circle)
	{
		double x, y, distance_squared;


		unsigned seed = 2;
	# pragma omp for
		for(toss = 0; toss < number_of_tosses; toss++) {
			x = my_drand(&seed)*2-1;
			//printf("%u\n", x);
			y = my_drand(&seed)*2-1;
			//printf("%e\n", y);
			distance_squared = x * x + y * y;
			if (distance_squared <= 1)
				number_in_circle++;
			}
	}

	pi_estimate = 4*number_in_circle/((double) number_of_tosses);
	printf("Answer: %f", pi_estimate);
}

//
