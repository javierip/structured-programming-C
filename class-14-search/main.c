/* Program: Binary search on array
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10

int read_key();
int binary_seach(int key, const int arr[], int n);
void print_array(const int arr[], int n);
void print_result(int key, int position);

int main()
{

    int array[N] = {2, 11, 27, 33, 45, 60, 72, 81, 90, 95};
    int key;
    int position_found;

    print_array(array, N);
    key = read_key();
    position_found = binary_seach(key, array, N);
    print_result(key, position_found);

    return 0;
}

int read_key()
{
    int key;
    printf("Which value are you searching?: ");
    scanf("%d", &key);
    return key;
}

int binary_seach(int key, const int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int middle;

    while (low <= high)
    {

        middle = (low + high) / 2;

        if (key == arr[middle])
            return middle;

        else if (key < arr[middle])
            high = middle - 1;

        else
            low = middle + 1;
    }

    return -1;
}

void print_array(const int arr[], int n)
{
    int i;
    printf("\nArray:\n");
    for (i = 0; i < n; i++)
        printf("a[%d]= %d\n", i, arr[i]);

    printf("\n");
}

void print_result(int key, int position)
{
    if (position < 0)
    {
        printf("Value not found\n", key);
    }
    else
    {
        printf("Value %d found in position %d\n", key, position);
    }
}
