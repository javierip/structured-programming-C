/* Program: Hanoi towers
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

const char LEFT = 'L';
const char CENTER = 'C';
const char RIGHT = 'R';

void move(int n, char pilaOrigen, char pilaDestino, char pilaTemp);

int main()
{
    int number_disks;

    printf("Welcome to Hanoi towers\n\n");
    printf("It is recommended not to go more than 10 disks\n\n");
    printf("How many disks do you want to use?: ");
    scanf("%d", &number_disks);

    move(number_disks, LEFT, RIGHT, CENTER);

    return 0;
}

void move(int disk_number, char origin, char target, char temporal)
{

    if (disk_number == 0)
        // Base case
        return;
    else
    {
        // Recursive case
        move(disk_number - 1, origin, temporal, target);

        printf("Move disk %d form %3c to %c.\n", disk_number, origin, target);

        move(disk_number - 1, temporal, target, origin);
    }
}
