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
    double a_double;
    long a_long;
    long long int a_long_long;
    short a_short;
    char letter, digit;

    integer_1 = 5;
    integer_2 = 10;

    printf("\n Silent and explicit conversions \n");
    a_double = integer_1 / integer_2;
    printf("Result of int division %lf \n", a_double);

    a_double = (double)integer_1 / (double)integer_2;
    printf("Result of explicit float division %lf \n", a_double);
    printf("Result of explicit float division with format %4.2lf \n", a_double);
    printf("Result of explicit float division with another format %.6lf \n", a_double);

    printf("\n Sizes \n");
    printf("Size of a double int bytes %d \n", sizeof(a_double));
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

    printf("\n ASCII and Hexadecimal \n");

    // A char stores its ASCII numeric value — the same byte printed three ways
    letter = 'A';
    printf("Char | Decimal | Hexadecimal\n");
    printf(" %c   |   %d    |   %X\n", letter, letter, letter);

    letter = 'a';
    printf(" %c   |   %d    |   %X\n", letter, letter, letter);

    digit = '0';
    printf(" %c   |   %d    |   %X\n", digit, digit, digit);

    // Arithmetic on chars works because they are integers
    letter = 'A';
    printf("'A' + 1 = '%c' (decimal %d)\n", letter + 1, letter + 1);

    // A hex literal is just another way to write an integer constant
    integer_1 = 0x41; // 65 in decimal = 'A' in ASCII
    printf("0x41 = decimal %d = character '%c'\n", integer_1, integer_1);

    integer_1 = 0xFF; // 255 in decimal
    printf("0xFF = decimal %d\n", integer_1);

    return 0;
}
