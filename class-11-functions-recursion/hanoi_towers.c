/* Program: Hanoi towers
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

const char LEFT = 'L';
const char CENTER = 'C';
const char RIGHT = 'R';

void move(int n, char origin_tower, char target_tower, char temp_tower);

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

void move(int number_disks, char origin_tower, char target_tower, char temp_tower)
{
    // Base case
    if (number_disks == 0)
    {
        return;
    }
    // Recursive case
    else
    {
        move(number_disks - 1, origin_tower, temp_tower, target_tower);
        printf("Move disk %d form %3c to %c.\n", number_disks, origin_tower, target_tower);
        move(number_disks - 1, temp_tower, target_tower, origin_tower);
    }
}
