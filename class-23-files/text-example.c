/* Program: Text file reading and writing example
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 * Description: Demonstrates file I/O operations in C including:
 *              - Creating text files with fprintf
 *              - Reading text files with fscanf
 *              - File handling with proper error checking
 *              - Different display modes for file content
 *              - File size calculation and statistics
 * Learning objectives:
 *              - File pointer management
 *              - Text file operations
 *              - Error handling for file operations
 *              - Formatted file input/output
 *              - File positioning (fseek, ftell)
 */

 /* fscanf example */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

long getFileSize(char* filePath)
{
    FILE* pFile = fopen(filePath, "r");
    if (pFile == NULL) return -1;

    // Move to end of file and get position
    fseek(pFile, 0, SEEK_END);
    long size = ftell(pFile);
    fclose(pFile);

    return size;
}

void readFile(char* camino, bool printLines)
{
    FILE* pFile;

    pFile = fopen(camino, "r");

    if (NULL == pFile)
    {
        printf("Can not open file %s\n", camino);
        return;
    }

    char inputString[80];

    int counter = 1;
    while (fscanf(pFile, "%s", inputString) != EOF)
    {
        if (printLines)
        {
            printf("word %d %s\n", counter, inputString);
        }
        else
        {
            printf("%s ", inputString);
        }
        counter++;
    }

    // Educational: Show total word count
    printf("\n[Total words read: %d]\n", counter - 1);

    fclose(pFile);
}

void createFile(char* camino)
{
    FILE* pFile;

    pFile = fopen(camino, "w");

    if (NULL == pFile)
    {
        printf("Can not open file %s\n", camino);
        return;
    }

    // Educational: Write different data types to demonstrate fprintf
    fprintf(pFile, "This is an example of text file.\n");
    fprintf(pFile, "We are writing multiple lines of text.\n");
    fprintf(pFile, "Each line is written using fprintf function.\n");
    fprintf(pFile, "Number example: %d\n", 42);              // Integer
    fprintf(pFile, "Float example: %.2f\n", 3.1416);         // Float with precision
    fprintf(pFile, "String example: %s\n", "Hello World");   // String
    fprintf(pFile, "Have a nice day.\n");

    fclose(pFile);
    printf("[File '%s' created successfully]\n", camino);
}

int main()
{
    char filePath[] = "myfile.txt";

    printf("=== File Operations Demo ===\n\n");

    printf("1. Trying to read non-existing file:\n");
    readFile(filePath, true);

    printf("2. Creating new file:\n");
    createFile(filePath);
    long fileSize = getFileSize(filePath);
    if (fileSize >= 0) printf("[File size: %ld bytes]\n\n", fileSize);

    printf("3. Reading file (with line numbers):\n");
    readFile(filePath, true);

    printf("4. Reading file (continuous text):\n");
    readFile(filePath, false);

    printf("\n\n=== Demo completed ===\n");

    return 0;
}