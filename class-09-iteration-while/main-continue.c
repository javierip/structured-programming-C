/* Program: Continue example
 * Description: This program demonstrates the use of the continue statement in a while loop.
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int odd_number_counter = 0;
    int user_input = 0;
    int addition_odd_numbers = 0;
    double average_odd_numers = 0.0;

    do
    {
        printf("Insert a value (-1 ends the program): ");
        scanf("%d", &user_input);

        if ((user_input % 2) == 0 || user_input == -1)
            continue;

        addition_odd_numbers = addition_odd_numbers + user_input;
        odd_number_counter++;

    } while (odd_number_counter < 100 && user_input != -1);

    average_odd_numers = (double)addition_odd_numbers / (double)odd_number_counter;

    printf("\n");
    printf("%d odd numbers were processed.\n", odd_number_counter);
    printf("Summ of off numbers: %d\n", addition_odd_numbers);
    printf("Average of odd numbers: %lf\n", average_odd_numers);

    return 0;
}