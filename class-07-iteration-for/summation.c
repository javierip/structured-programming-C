/* Program: Summation from 1 up to n of 1/i
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */
#include <stdlib.h>
#include <stdio.h>

int main()
{

    int i;
    int n;
    double result;

    printf("Value of n?: ");
    scanf("%d", &n);

    result = 0.0;

    for (i = 1; i <= n; i++)
    {
        result = result + 1.0 / (double)i;
    }

    printf("The summation of %d terms of 1/i is %lf\n", n, result);

    return 0;
}
