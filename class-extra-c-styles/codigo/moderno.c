#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define FILENAME    "archivo1.txt"
#define RANGO_MIN   1000
#define RANGO_MAX   2000

/* ---------- Prototipos ---------- */
static bool generarArchivo(size_t n);
static bool cargarArchivo(int *arreglo, size_t n);
static void ordenarInsercion(int *arreglo, size_t n);
static void imprimirArreglo(const int *arreglo, size_t n);
static bool leerCantidad(size_t *n);

/* ---------- a. Genera el archivo con N numeros aleatorios ---------- */
static bool generarArchivo(size_t n)
{
    FILE *f = fopen(FILENAME, "w");
    if (!f) {
        fprintf(stderr, "Error: no se pudo crear %s\n", FILENAME);
        return false;
    }

    for (size_t i = 0; i < n; i++) {
        int numero = RANGO_MIN + rand() % (RANGO_MAX - RANGO_MIN + 1);
        if (fprintf(f, "%d\n", numero) < 0) {
            fprintf(stderr, "Error: fallo al escribir en el archivo\n");
            fclose(f);
            return false;
        }
    }

    fclose(f);
    return true;
}

/* ---------- b. Carga N numeros del archivo a un arreglo ---------- */
static bool cargarArchivo(int *arreglo, size_t n)
{
    FILE *f = fopen(FILENAME, "r");
    if (!f) {
        fprintf(stderr, "Error: no se pudo abrir %s\n", FILENAME);
        return false;
    }

    for (size_t i = 0; i < n; i++) {
        if (fscanf(f, "%d", &arreglo[i]) != 1) {
            fprintf(stderr, "Error: archivo con menos datos de los esperados\n");
            fclose(f);
            return false;
        }
    }

    fclose(f);
    return true;
}

/* ---------- c. Ordenamiento por insercion ---------- */
static void ordenarInsercion(int *arreglo, size_t n)
{
    for (size_t i = 1; i < n; i++) {
        int clave = arreglo[i];
        size_t j = i;

        while (j > 0 && arreglo[j - 1] > clave) {
            arreglo[j] = arreglo[j - 1];
            j--;
        }
        arreglo[j] = clave;
    }
}

/* ---------- d. Impresion del arreglo ---------- */
static void imprimirArreglo(const int *arreglo, size_t n)
{
    for (size_t i = 0; i < n; i++) {
        printf("%d\n", arreglo[i]);
    }
}

/* ---------- Lectura segura de la cantidad de elementos ---------- */
static bool leerCantidad(size_t *n)
{
    char linea[64];

    printf("Ingrese la cantidad de elementos a usar: ");
    if (!fgets(linea, sizeof linea, stdin)) {
        return false;
    }

    char *endptr;
    long valor = strtol(linea, &endptr, 10);

    if (endptr == linea || valor <= 0) {
        return false;
    }

    *n = (size_t) valor;
    return true;
}

/* ---------- e. main ---------- */
int main(void)
{
    srand((unsigned int) time(NULL));

    size_t n = 0;
    if (!leerCantidad(&n)) {
        fprintf(stderr, "Entrada invalida.\n");
        return EXIT_FAILURE;
    }

    int *arreglo = malloc(n * sizeof *arreglo);
    if (!arreglo) {
        fprintf(stderr, "Error: no se pudo reservar memoria.\n");
        return EXIT_FAILURE;
    }

    bool ok = generarArchivo(n) && cargarArchivo(arreglo, n);
    if (!ok) {
        free(arreglo);
        return EXIT_FAILURE;
    }

    ordenarInsercion(arreglo, n);

    printf("\nArreglo ordenado:\n");
    imprimirArreglo(arreglo, n);

    free(arreglo);
    return EXIT_SUCCESS;
}
