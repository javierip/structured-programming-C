/* Programa: Cadenas en español y configuración regional con <locale.h>
 * Autor: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu.ar
 *
 * Este archivo está guardado en UTF-8. En UTF-8 las letras sin acento
 * ocupan 1 byte, pero letras como 'á' o 'ñ' ocupan 2 bytes.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h> // solo para SetConsoleOutputCP
#endif

#define LINE_LENGTH 80

// Cuenta letras en lugar de bytes: en UTF-8, los bytes que continúan
// una letra tienen la forma 10xxxxxx y no se cuentan
int contarLetras(const char *texto)
{
    int letras = 0;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (((unsigned char)texto[i] & 0xC0) != 0x80)
            letras++;
    }
    return letras;
}

// Prueba varios nombres de configuración regional en español, porque
// cada sistema operativo los escribe distinto. Devuelve el que funcionó.
const char *configurarEspanol(void)
{
    const char *nombres[] = {
        "es_AR.UTF-8", // Linux, macOS y Windows 10 o posterior
        "es_ES.UTF-8",
        "es-AR",       // Windows
        "Spanish",     // Windows (nombre antiguo)
    };
    int cantidad = sizeof(nombres) / sizeof(nombres[0]);

    for (int i = 0; i < cantidad; i++)
    {
        if (setlocale(LC_ALL, nombres[i]) != NULL)
            return nombres[i];
    }
    return NULL;
}

void mostrarNumerosYFecha(void)
{
    struct lconv *formato = localeconv();
    char fecha[LINE_LENGTH];
    time_t ahora = time(NULL);

    printf("   Número real: %.2f\n", 1234.56);
    printf("   Separador decimal: '%s'\n", formato->decimal_point);

    strftime(fecha, LINE_LENGTH, "%A %d de %B de %Y", localtime(&ahora));
    printf("   Fecha de hoy: %s\n", fecha);
}

int main(void)
{
    char palabra[LINE_LENGTH] = "año";
    char saludo[LINE_LENGTH] = "señor García";
    const char *configuracion;

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // la consola de Windows muestra UTF-8
#endif

    printf("1. Texto con acentos y signos del español:\n");
    printf("   ¿Cómo estás? ¡Bienvenido al curso de programación!\n\n");

    printf("2. strlen cuenta bytes, no letras:\n");
    printf("   strlen(\"%s\") = %zu bytes\n", palabra, strlen(palabra));
    printf("   contarLetras(\"%s\") = %d letras\n\n", palabra, contarLetras(palabra));

    printf("3. toupper cambia de a un byte, por eso no convierte la 'ñ' ni la 'í':\n");
    for (int i = 0; saludo[i] != '\0'; i++)
        saludo[i] = (char)toupper((unsigned char)saludo[i]);
    printf("   %s\n\n", saludo);

    // Todo programa en C arranca con la configuración "C" (estilo inglés)
    printf("4. Configuración regional inicial: %s\n", setlocale(LC_ALL, NULL));
    mostrarNumerosYFecha();

    configuracion = configurarEspanol();
    if (configuracion == NULL)
    {
        printf("\nNo hay una configuración regional en español instalada.\n");
        printf("En Linux se instala con: sudo locale-gen es_AR.UTF-8\n");
        return 1;
    }

    printf("\n5. Configuración regional en español: %s\n", configuracion);
    mostrarNumerosYFecha();

    return 0;
}
