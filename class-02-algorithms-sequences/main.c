/* Program: Variables and sequences
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

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
