/* Program: Time measurement
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void measure_time();

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        measure_time();
    }
    return 0;
}

void measure_time()
{
    static long accumulated_time = 0;

    long initial_time = clock();
    long actual_time = clock();
    long delta = 0.0;

    do
    {
        actual_time = clock();
        delta = actual_time - initial_time;

    } while (delta < 2500);

    accumulated_time += delta;

    printf("This execution took [ms] = %ld. Total time [ms] = %ld\n", delta, accumulated_time);
}