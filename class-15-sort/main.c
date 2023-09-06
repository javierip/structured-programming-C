/* Program: Insertion sort example
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define N 4

void insertionSort(int arr[], int n)
{
    int pass, temp, j;
    for (pass = 1; pass < n; pass++)
    {
        temp = arr[pass];
        j = pass - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[N] = {12, 11, 13, 5, 6};
    int n = N;

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
