/* Program: Dynamic memory example
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct
{
    double x;
    double y;
} Point;


int getNumberOfPoints();
Point* gerPointNumber(int n);
void loadData(Point arr[], int n);
void printData(char *titulo,  Point *arr, int n);
double getDistance(Point p);
void sortByDistance( Point *arr, int n );

int main()
{
    int n;
    Point *array;
    n = getNumberOfPoints();

    array = gerPointNumber(n);
    if (array == NULL)
    {
        printf("No memory allocated\n");
        return -1;
    }
    else
    {
        loadData(array, n);
        printData("Loaded array", array, n);
        sortByDistance(array, n);
        printData("Sorted array", array, n);

        free(array);
        array = NULL;

        return 0;
    }
}

int getNumberOfPoints()
{
    int n;
    printf("How may points will you need? ");
    scanf("%d", &n);
    printf("\n");
    return n;
}
Point* gerPointNumber(int n)
{
    Point *arrPts;

    arrPts = (Point*)malloc(n * sizeof(Point));
    if (arrPts == NULL)
        return NULL;

    return arrPts;
}

void printData(char *title, Point *arr, int n)
{
    int i;
    printf("\n%s\n", title);
    for (i = 0; i<n; i++)
        printf("p[%d]: X= %6.2lf  Y= %6.2lf Dist= %6.2lf\n",
               i, arr[i].x, arr[i].y, getDistance(arr[i]));
    printf("\n");

}

void loadData(Point arr[], int n)
{
    int i;
    for (i = 0; i<n; i++)
    {
        printf("Point %d:\n", i);
        printf("   x= ");
        scanf("%lf", &arr[i].x);
        printf("   y= ");
        scanf("%lf", &arr[i].y);
        printf("\n");
    }

}

void sortByDistance( Point *arr, int n )
{
    int pasada;
    int j, posMin;
    Point temp;

    for (pasada = 0; pasada<n; pasada++)
    {
        posMin = pasada;
        for (j = posMin; j<n; j++)
        {
            if (getDistance(arr[j]) < getDistance(arr[posMin]))
                posMin = j;
        }
        temp = arr[posMin];
        arr[posMin] = arr[pasada];
        arr[pasada] = temp;
    }
}

double getDistance(Point p)
{
    double dist = p.x * p.x + p.y * p.y;
    dist = sqrt(dist);
    return dist;
}
