/* Program: Temperature scale converter
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double celsius_to_fahrenheit(double value)
{
    return value * 9.0 / 5.0 + 32;
}
double celcius_a_kelvin(double value)
{
    return value + 273.15;
}

int main()
{
    double temp_celsius, temp_fahrenheit, temp_kelvin;

    printf("Insert temperature in Celsius scale: ");
    scanf("%lf", &temp_celsius);

    printf("Temperature in Fahrenheit scale is: %4.2lf\n", celsius_to_fahrenheit(temp_celsius));
    printf("Temperature in Kelvin scale is: %4.2lf\n", celcius_a_kelvin(temp_celsius));
	
	printf("End of program\n");

    return 0;
}
