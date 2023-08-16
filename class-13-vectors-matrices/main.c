/* Program: Do matrix operations
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3

void add_matrices(double c[N][N], const double a[N][N], const double b[N][N])
{
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			c[i][j] = a[i][j] + b[i][j];

	return;
}

void multiply_matrices(double c[N][N], const double a[N][N], const double b[N][N])
{
	int i, j, k;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			c[i][j] = 0.0;
			for (k = 0; k < N; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return;
}

void print_matrix(const double arr[N][N])
{
	int i, j;

	printf("Matrix\n");

	for (i = 0; i < N; i++)
	{
		printf("\n");
		for (j = 0; j < N; j++)
			printf("%13.2lf ", arr[i][j]);
	}
	printf("\n\n");
}

int main(void)
{
	double matrix_a[N][N] = {
		{2.0, -1., 0.0},
		{0.0, 2.0, 9.3},
		{3.5, 0.0, 2.0}};

	double matrix_b[N][N] = {
		{1.0, 0.0, -1},
		{2.4, 1.0, 0.0},
		{6.3, 0.0, 1.0}};

	double matrix_c[N][N] = {
		{1.0, 2.2, 0.0},
		{0.0, 1.0, -1.4},
		{5.3, 4.1, 1.0}};

	double addition[N][N];
	double result[N][N];

	add_matrices(addition, matrix_a, matrix_b);
	multiply_matrices(result, matrix_c, addition);
	print_matrix(result);

	return 0;
}
