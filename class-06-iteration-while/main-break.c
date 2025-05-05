/* Program: Break example
 * Description: This program demonstrates the use of the break statement in a while loop.
 * The program prompts the user to enter a value and calculates its double. The loop continues until the user enters -1, at which point the program ends.
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iteration_counter = 0;
    int user_selection;

    while (iteration_counter < 100)
    {

        printf("Insert a value (-1 ends the program): ");
        scanf("%d", &user_selection);

        if (user_selection == -1)
            break;

        printf("The double of the value is %d \n", user_selection * 2);

        iteration_counter++;
    }

    printf("End of program.\n");
    return 0;
}