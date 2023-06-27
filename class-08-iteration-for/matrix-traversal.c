/* Program: Loops through an 2D array in an "L" pattern
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */
#include <stdio.h>
#include <stdlib.h>

#define N_COLUMNS 10
#define N_ROWS 10
#define N_LAPS 10

int main()
{
    int row = 0, column = 0, lap;

    int matrix[N_COLUMNS][N_ROWS] = {0};

    // load values
    for (row = 0; row < N_COLUMNS; row++)
    {
        for (column = 0; column < N_COLUMNS; column++)
        {
            matrix[row][column] = 10 * row + column;
        }
    }

    // print content
    for (row = 0; row < N_COLUMNS; row++)
    {
        for (column = 0; column < N_COLUMNS; column++)
        {
            printf("%02d ", matrix[row][column]);
        }
        printf("\n");
    }
    printf("\n");

    // follow L path
    for (lap = 0; lap < N_LAPS; lap++)
    {
        column = 0 + lap;
        for (row = 0; row < N_ROWS - lap; row++)
            printf("%02d ", matrix[row][column]);

        printf("\n");
        row = 9 - lap;
        for (column = 1 + lap; column < N_COLUMNS; column++)
            printf("%02d ", matrix[row][column]);
        printf("\n");
    }

    return 0;
}
