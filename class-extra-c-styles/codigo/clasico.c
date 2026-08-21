#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "archivo1.txt"

/* a. Genera un archivo de texto secuencial con N numeros aleatorios en [1000,2000] */
void generarArchivo(int n)
{
    FILE *f = fopen(FILENAME, "w");
    if (f == NULL) {
        printf("Error al crear el archivo.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        int numero = 1000 + rand() % 1001; /* rango [1000,2000] */
        fprintf(f, "%d\n", numero);
    }

    fclose(f);
}

/* b. Carga N numeros desde el archivo al arreglo pasado como parametro */
void cargarArchivo(int arreglo[], int n)
{
    FILE *f = fopen(FILENAME, "r");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &arreglo[i]);
    }

    fclose(f);
}

/* c. Ordena por insercion un arreglo de N elementos */
void ordenarInsercion(int arreglo[], int n)
{
    for (int i = 1; i < n; i++) {
        int clave = arreglo[i];
        int j = i - 1;

        while (j >= 0 && arreglo[j] > clave) {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = clave;
    }
}

/* d. Imprime el arreglo de N enteros ordenados por pantalla */
void imprimirArreglo(int arreglo[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d\n", arreglo[i]);
    }
}

/* e. Programa principal */
int main(void)
{
    int n;

    srand((unsigned int) time(NULL));

    printf("Ingrese la cantidad de elementos a usar: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("La cantidad debe ser un numero positivo.\n");
        return 1;
    }

    int *arreglo = (int *) malloc(n * sizeof(int));
    if (arreglo == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    generarArchivo(n);
    cargarArchivo(arreglo, n);
    ordenarInsercion(arreglo, n);

    printf("\nArreglo ordenado:\n");
    imprimirArreglo(arreglo, n);

    free(arreglo);

    return 0;
}
