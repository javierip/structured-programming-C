/* Program: Text file reading and writing example (sequential access)
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 *
 * Creates a text file with fprintf, then reads it sequentially
 * line by line (fgets) and word by word (fscanf).
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define LINE_LENGTH 80

// Returns the file size in bytes, or -1 if the file can not be opened
long getFileSize(const char *path)
{
    FILE *pFile = fopen(path, "rb"); // binary mode: ftell gives bytes
    long size;

    if (pFile == NULL)
        return -1;

    fseek(pFile, 0, SEEK_END);
    size = ftell(pFile);
    fclose(pFile);

    return size;
}

void createFile(const char *path)
{
    FILE *pFile = fopen(path, "w");

    if (pFile == NULL)
    {
        printf("Can not open file %s\n", path);
        return;
    }

    fprintf(pFile, "This is an example of text file.\n");
    fprintf(pFile, "We are writing multiple lines of text.\n");
    fprintf(pFile, "Each line is written using fprintf function.\n");
    fprintf(pFile, "Number example: %d\n", 42);
    fprintf(pFile, "Float example: %.2f\n", 3.1416);
    fprintf(pFile, "String example: %s\n", "Hello World");
    fprintf(pFile, "Have a nice day.\n");

    fclose(pFile);
    printf("[File '%s' created]\n", path);
}

// Reads the file one line at a time with fgets
void readLines(const char *path)
{
    FILE *pFile = fopen(path, "r");
    char line[LINE_LENGTH];
    int counter = 0;

    if (pFile == NULL)
    {
        printf("Can not open file %s\n\n", path);
        return;
    }

    while (fgets(line, LINE_LENGTH, pFile) != NULL)
    {
        counter++;
        printf("line %d: %s", counter, line); // line already ends with '\n'
    }
    printf("[Total lines read: %d]\n\n", counter);

    fclose(pFile);
}

// Reads the file one word at a time with fscanf
void readWords(const char *path)
{
    FILE *pFile = fopen(path, "r");
    char word[LINE_LENGTH];
    int counter = 0;

    if (pFile == NULL)
    {
        printf("Can not open file %s\n\n", path);
        return;
    }

    // %79s limits the word length to avoid overflowing the buffer
    while (fscanf(pFile, "%79s", word) == 1)
    {
        counter++;
        printf("%s ", word);
    }
    printf("\n[Total words read: %d]\n\n", counter);

    fclose(pFile);
}

int main(void)
{
    const char *filePath = "myfile.txt";
    long fileSize;

    printf("=== File Operations Demo ===\n\n");

    remove(filePath); // start from scratch on every run

    printf("1. Trying to read a non-existing file:\n");
    readLines(filePath);

    printf("2. Creating the file:\n");
    createFile(filePath);
    fileSize = getFileSize(filePath);
    if (fileSize >= 0)
        printf("[File size: %ld bytes]\n\n", fileSize);

    printf("3. Reading the file line by line:\n");
    readLines(filePath);

    printf("4. Reading the file word by word:\n");
    readWords(filePath);

    printf("=== Demo completed ===\n");

    return 0;
}
