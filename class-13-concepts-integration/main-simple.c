/* Program: Math toolbox - simple version (concept integration, weeks 9 to 12)
 * Description: Menu-driven program that combines:
 *   - do-while menu and switch       (week 9)
 *   - for loop (iterative factorial) (week 10)
 *   - functions with prototypes      (week 11)
 *   - recursion (factorial)          (week 12)
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

long factorial_recursive(int n);
long factorial_iterative(int n);

int main()
{
    int user_option = 0;
    int input_value = 0;

    do
    {
        printf("\n");
        printf("=== Math toolbox ===\n");
        printf(" 1. Factorial (recursive)\n");
        printf(" 2. Factorial (iterative)\n");
        printf(" 3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &user_option);

        switch (user_option)
        {
        case 1:
            printf("Value of n?: ");
            scanf("%d", &input_value);
            if (input_value < 0)
                printf("Factorial is not defined for negatives.\n");
            else
                printf("%d! = %ld\n",
                       input_value, factorial_recursive(input_value));
            break;

        case 2:
            printf("Value of n?: ");
            scanf("%d", &input_value);
            if (input_value < 0)
                printf("Factorial is not defined for negatives.\n");
            else
                printf("%d! = %ld\n",
                       input_value, factorial_iterative(input_value));
            break;

        case 3:
            printf("End of program.\n");
            break;

        default:
            printf("Invalid option.\n");
        }

    } while (user_option != 3);

    return 0;
}

// Recursive factorial (week 12).
long factorial_recursive(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

// Iterative factorial with a for loop (week 10).
long factorial_iterative(int n)
{
    long result = 1;
    int i;
    for (i = 2; i <= n; i++)
        result *= i;
    return result;
}
