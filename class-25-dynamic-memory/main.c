/* Program: Dynamic memory example
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 *
 * Reads n points from the keyboard into an array allocated at runtime,
 * sorts them by their distance to the origin and frees the memory.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

void clearInputBuffer(void);
int getNumberOfPoints(void);
double readDouble(const char *prompt);
Point *allocatePoints(int n);
void loadData(Point arr[], int n);
void printData(Point *arr, int n);
double getDistance(Point p);
void sortByDistance(Point *arr, int n);

int main(void)
{
    int n;
    Point *array;

    n = getNumberOfPoints();

    array = allocatePoints(n);
    if (array == NULL)
    {
        printf("No memory allocated\n");
        return EXIT_FAILURE;
    }

    loadData(array, n);
    printf("\nLoaded array\n");
    printData(array, n);

    sortByDistance(array, n);
    printf("\nSorted array\n");
    printData(array, n);

    free(array);
    array = NULL; // avoid using a dangling pointer by mistake

    return EXIT_SUCCESS;
}

// Discards the rest of the current input line
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Asks until the user enters a positive integer
int getNumberOfPoints(void)
{
    int n;

    printf("How many points will you need? ");
    while (scanf("%d", &n) != 1 || n <= 0)
    {
        clearInputBuffer();
        printf("Please enter a positive integer: ");
    }
    clearInputBuffer();
    printf("\n");

    return n;
}

// Shows the prompt and asks until the user enters a valid number
double readDouble(const char *prompt)
{
    double value;

    printf("%s", prompt);
    while (scanf("%lf", &value) != 1)
    {
        clearInputBuffer();
        printf("Invalid number, try again: ");
    }
    clearInputBuffer();

    return value;
}

// Returns an array of n points, or NULL if malloc fails
Point *allocatePoints(int n)
{
    return (Point *)malloc(n * sizeof(Point));
}

void printData(Point *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("p[%d]: X= %6.2lf  Y= %6.2lf Dist= %6.2lf\n",
               i, arr[i].x, arr[i].y, getDistance(arr[i]));
    printf("\n");
}

void loadData(Point arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Point %d:\n", i);
        arr[i].x = readDouble("   x= ");
        arr[i].y = readDouble("   y= ");
        printf("\n");
    }
}

// Selection sort, from the closest to the farthest point
void sortByDistance(Point *arr, int n)
{
    int pass;
    int j, posMin;
    double distMin, dist;
    Point temp;

    for (pass = 0; pass < n - 1; pass++)
    {
        posMin = pass;
        distMin = getDistance(arr[pass]);
        for (j = pass + 1; j < n; j++)
        {
            dist = getDistance(arr[j]);
            if (dist < distMin)
            {
                posMin = j;
                distMin = dist;
            }
        }
        if (posMin != pass)
        {
            temp = arr[posMin];
            arr[posMin] = arr[pass];
            arr[pass] = temp;
        }
    }
}

// Distance from p to the origin (0, 0)
double getDistance(Point p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}
