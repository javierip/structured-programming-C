/* Program: Vectors example
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>

#define N 3

double globalArray[N] = {0.0}; // Global array - static - initialized

void printArray(double arr[], int size)
{
	int i;
	for (int i = 0; i < size; i++)
		printf("arr[%d]= %.2lf\n", i, arr[i]);
	printf("\n");
}

int main(void)
{
	double locaArrayA[N] = {1., 3., 6.}; // local array - automatic - initialized
	double locaArrayB[N];				 // local array - automatic - uninitialized
	static double locaArrayC[N] = {0.0}; // local array - static - initialized to 0

	printf("arrayA\n");
	printArray(locaArrayA, N);
	printf("arrayB\n");
	printArray(locaArrayB, N);
	printf("arrayC\n");
	printArray(locaArrayC, N);
	printf("globalArray\n");
	printArray(globalArray, N);

	return 0;
}
