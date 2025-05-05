/* Program: Sports selector
 * Description: This program allows the user to select a sport from a menu. The program continues to display the menu until the user chooses to exit.
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int user_option = 0;
    do
    {
        printf("\n");
        printf("Select your sport \n\n");
        printf(" * 1. Swiming \n");
        printf(" * 2. Volley \n");
        printf(" * 3. Futbol\n");
        printf(" * 4. End\n");
        printf("\n");
        printf("Choose an option: ");
        scanf("%d", &user_option);

        switch (user_option)
        {
        case 1:
            printf("Splash!\n");
            break;
        case 2:
            printf("Check the net!\n");
            break;
        case 3:
            printf("Kick!\n");
            break;
        case 4:
            printf("End of program.\n");
            break;
        default:
            printf("Invalid option\n");
        }

    } while (user_option != 4);

    return 0;
}