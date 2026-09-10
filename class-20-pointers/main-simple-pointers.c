/* Program: Walk an array using pointers
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define N 4

int main()
{
    int array[N] = {10, 20, 30, 40};
    int* pointer_begin = array;
    int* pointer_end = pointer_begin + N;
    int* a_pointer;
    int i;

    printf("Walk an array without using pointers \n");
    for (i = 0; i < N; i++)
        printf("Address %p: %d\n", &(array[i]), array[i]);
    printf("\n");

    printf("Walk an array using pointer arithmetic and a while instruction \n");
    a_pointer = pointer_begin;
    while (a_pointer < pointer_end)
    {
        printf("Address %p: %d\n", a_pointer, *a_pointer);
        a_pointer++;
    }
    printf("\n");

    printf("Walk an array using pointer arithmetic and a for instruction \n");
    for(a_pointer = pointer_begin; a_pointer < pointer_end; a_pointer++ )
        printf("Address %p: %d\n", a_pointer, *a_pointer);

    printf("\n");

    printf("Use array name as a pointer \n");
    for (i = 0; i < N; i++)
        printf("Address %p: %d\n", array + i, *(array + i));

    printf("\n");

    return 0;
}
