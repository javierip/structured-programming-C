/* Program: Types, conversion, and limits
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 * reference 1: https://cplusplus.com/reference/climits/
 * reference 2: https://cplusplus.com/reference/cstdio/fprintf/
 * reference 3: https://cplusplus.com/reference/cfloat/
 */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int integer_1, integer_2;
    double result;
    long a_long;
    long long int a_long_long;
    short a_short;

    integer_1 = 5;
    integer_2 = 10;

    printf("\n Silent and explicit conversions \n");
    result = integer_1 / integer_2;
    printf("Result of int division %lf \n", result);

    result = (double)integer_1 / (double)integer_2;
    printf("Result of explicit float division %lf \n", result);
    printf("Result of explicit float division with format %4.2lf \n", result);
    printf("Result of explicit float division with another format %.6lf \n", result);

    printf("\n Sizes \n");
    printf("Size of a float int bytes %d \n", sizeof(result));
    printf("Size of an integer bytes %d \n", sizeof(integer_1));
    printf("Size of an short bytes %d \n", sizeof(a_short));
    printf("Size of an long bytes %d \n", sizeof(a_long));
    printf("Size of an long long bytes %d \n", sizeof(a_long_long));

    printf("\n Max values and sizes \n");
    integer_1 = INT_MAX;
    a_short = a_long = LONG_MAX;

    printf("Value of short %d \n", a_short);
    printf("Value of long %ld \n", a_long);
    printf("Value of int %d \n", integer_1);

    integer_2 = INT_MIN;
    printf("Min value of int %d \n", integer_2);

    integer_1 = a_long_long = LLONG_MAX;
    printf("Value of long long %lld\n", a_long_long);
    printf("Value of int %d\n", integer_1);

    return 0;
}

