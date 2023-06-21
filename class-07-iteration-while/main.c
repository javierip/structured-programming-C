/* Program: Secret number
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber;
    int guessedNumber;

    srand(time(NULL));

    // generate number
    secretNumber = rand() % 100;

    int end_arrived = 0;
    while (!end_arrived)
    {

        printf("Valor? ");
        scanf("%d", &guessedNumber);

        // Correct number
        if (guessedNumber == secretNumber)
            end_arrived = 1;

        // Low number
        else if (guessedNumber < secretNumber)
            printf("Too low. Insert a higher value.\n");

        // High number
        else
            printf("Too high. Insert a lower number\n");
    }

    printf("You reached the correct number!\n");

    return 0;
}