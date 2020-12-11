/**************************************************************

 The program reads a BMP image file and creates a new
 image that is the negative or desaturated of the input file.

 **************************************************************/

#include "qdbmp.h"
#include <stdio.h>
#include <omp.h>

typedef enum {desaturate, negative} ImgProcessing ;

/* Creates a negative image of the input bitmap file */
int main() {
	const char* inFile = "okanagan.bmp";
	const char* outFile = "okanagan.bmp";
	const ImgProcessing processingType = desaturate; //or negative

	UCHAR r, g, b;
	UINT width, height;
	UINT x, y;
	BMP* bmp;

	/* Read an image file */
	bmp = BMP_ReadFile(inFile);
	BMP_CHECK_ERROR(stdout, -1);

	/* Get image's dimensions */
	width = BMP_GetWidth(bmp);
	height = BMP_GetHeight(bmp);

	double t = omp_get_wtime();
	
	int num_threads = 4;
	int subsize = width/num_threads;

#pragma omp parallel num_threads(num_threads) private(x,y,r,g,b)
	{

		// get thread id (tid)
		int tid = omp_get_thread_num();
		int first = tid*subsize;
		int last = (tid+1)*subsize;

		/* Iterate through all the image's pixels */
		#pragma omp for
			for (x = first; x < last; ++x) {
				//#pragma omp parallel for -------------ANSWER TO Q1b------------------------------------------------------------------
				for (y = 0; y < height; ++y) { 			//Using a nested parallel for loop here (for the y-loop) doesn't improve speed,
														// and may cause overhead.
					BMP_GetPixelRGB(bmp, x, y, &r, &g, &b);

					/* Write new RGB values */
					if(processingType == negative)
						BMP_SetPixelRGB(bmp, x, y, 255 - r, 255 - g, 255 - b);
					else if(processingType == desaturate){
						UCHAR gray = r * 0.3 + g * 0.59 + b * 0.11;
						BMP_SetPixelRGB(bmp, x, y, gray, gray, gray);
					}
				}
			}
	}
	/* calculate and print processing time*/
	t = 1000 * (omp_get_wtime() - t);
	printf("Finished image processing in %.1f ms.", t);

	/* Save result */
	BMP_WriteFile(bmp, outFile);
	BMP_CHECK_ERROR(stdout, -2);

	/* Free all memory allocated for the image */
	BMP_Free(bmp);

	return 0;
}
