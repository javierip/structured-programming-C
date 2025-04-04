/* Program: Variables and sequences
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

// See this site for more information: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/scanf-scanf-s?view=msvc-160
// This site "hacks" the warning https://yyoungha.github.io/c/warning/post/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int edad;
    double peso_actual, peso_al_nacer, aumento_peso;

    printf("Hola! ");
    printf("Hello!\n");

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese su peso al nacer: ");
    scanf("%lf", &peso_al_nacer);

    printf("Ingrese su peso actual: ");
    scanf("%lf", &peso_actual);

    aumento_peso = peso_actual - peso_al_nacer;

    printf("Usted tiene %d anios\n", edad);
    printf("Actualmente pesa %lf kg.\n", peso_actual);
    printf("Ha aumentado %lf kilos.\n", aumento_peso);

    return 0;
}
