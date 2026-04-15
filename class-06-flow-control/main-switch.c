/* Program: Month number to name
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int month;

    // Ask for input
    printf("Which is the actual month? ");
    scanf("%d", &month);
    printf("Current month is ");

    // Convert
    switch (month)
    {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August ");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    default:
        printf("ERROR");
        break;
    }

    printf("\n");

    return 0;
}