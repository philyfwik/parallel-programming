/*
 ============================================================================
 Name        : A1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int u1, u2, u3, u4;
	printf("Enter four integers: ");
	scanf("%d %d %d %d", &u1, &u2, &u3, &u4);
	//printf("You typed %d, %d, %d and %d", u1, u2, u3, u4);

	int count=0;
	float av = (u1+u2+u3+u4)/4.0;
	int a[] = {u1, u2, u3, u4};
	int len = sizeof(a) / sizeof(a[0]);
	int i;
	for (i=0; i<len; i++){
		if (a[i] > av)
			count++;
	}

	if (count == 1)
		printf("There is %d entry above the average (%.1f)", count, av);
	else
		printf("There are %d entries above the average (%.1f)", count, av);
	return 0;
//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	return EXIT_SUCCESS;
}
