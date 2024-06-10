/* Program: Recursive factorial
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

long factorial(int n);

int main()
{
    int user_input;
    long result = 0;

    printf("Value of n?: ");
    scanf("%d", &user_input);

    result = factorial(user_input);

    printf("%d! = %ld \n", user_input, result);

    return 0;
}

long factorial(int n)
{
    // base case
    if (n == 0)
        return 1;
    else
        // recursive case
        return (n * factorial(n - 1));
}