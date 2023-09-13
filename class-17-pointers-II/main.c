/* Program: Functions examples using pointers
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define N 4

void add_10_reference(int* variable)
{
    *variable = *variable + 10;
}

void add_10_value(int variable)
{
    variable = variable + 10;
}

void cartesian_to_polar(double x, double y, double* rho, double* phi)
{
    *rho = sqrt(x * x + y * y);
    *phi = atan2(y, x);	// radians
}

void sort_pointers( int *ptr[], int n )
{
    int pass;
    int j, min_pos;
    int *temp;

    for (pass = 0; pass< n-1; pass++)
    {

        min_pos = pass;
        for (j=pass+1; j<n; j++)
        {
            if (*ptr[j] < *ptr[min_pos])
                min_pos = j;
        }

        temp = ptr[min_pos];
        ptr[min_pos] = ptr[pass];
        ptr[pass] = temp;
    }
}

void print_pointers( int *ptr[], int n )
{
    int i;

    for( i=0; i<n; i++ )
        printf("pointer [%d]=%p, data=%d\n", i, ptr[i], *ptr[i] );

    printf("\n");

    return;
}

void init_pointers( int *ptr[], int data[], int n )
{
    int i;

    for( i=0; i<n; i++ )
    {
        data[i] = i + 100 - 3;
        ptr[i] = &data[i] ;
    }
    return;
}

int main()
{
    int a_variable = 1;

    // value and reference difference
    printf("Variable at main: %d\n", a_variable);
    add_10_reference(&a_variable);
    printf("Variable at main after add_10_reference: %d\n", a_variable);
    add_10_value(a_variable);
    printf("Variable at main after add_10_value: %d\n", a_variable);

    // two arguments functions
    double radius, angle, x = 10.0, y = 10.0;
    cartesian_to_polar(x, y, &radius, &angle);
    printf("x= %lf y= %lf radius= %lf angle= %lf\n", x, y, radius, angle);

    // ponters and arrays
    int *ptr[N];
    int data[N];
    init_pointers(ptr, data, N);
    printf("Before sorting\n");
    print_pointers(ptr, N);
    sort_pointers(ptr, N);
    printf("After sorting\n");
    print_pointers(ptr, N);

    return 0;
}
