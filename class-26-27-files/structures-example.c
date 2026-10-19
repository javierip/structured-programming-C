/* Program: Binary file of structures example (direct access)
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 *
 * Saves an array of structures to a binary file with fwrite, reads it
 * back with fread, and then uses fseek to read and update a single
 * record without going through the whole file.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 10
#define FILENAME "data.bin"

typedef struct
{
    int id;
    char name[50];
    float weight;
} Student;

// Fills the array with sample data
void generateStructures(Student data[], int count)
{
    // Clear everything first so no garbage bytes end up in the file
    memset(data, 0, count * sizeof(Student));

    for (int i = 0; i < count; i++)
    {
        data[i].id = i + 1;
        sprintf(data[i].name, "Student %d", i + 1);
        data[i].weight = 50.0f + (float)rand() / RAND_MAX * 50.0f; // 50 to 100
    }
}

// Writes all the structures in one call. Returns 1 on success, 0 on failure
int saveStructuresToFile(const char *filename, Student data[], int count)
{
    FILE *file = fopen(filename, "wb");
    size_t written;

    if (file == NULL)
    {
        perror("Error opening file for writing");
        return 0;
    }

    written = fwrite(data, sizeof(Student), count, file);
    fclose(file);

    if (written != (size_t)count)
    {
        fprintf(stderr, "Error writing data to file. Written %zu items\n", written);
        return 0;
    }

    printf("%d structures saved to %s\n", count, filename);
    return 1;
}

// Reads up to maxCount structures. Returns how many were read, or -1 on error
int readStructuresFromFile(const char *filename, Student data[], int maxCount)
{
    FILE *file = fopen(filename, "rb");
    size_t numRead;

    if (file == NULL)
    {
        perror("Error opening file for reading");
        return -1;
    }

    numRead = fread(data, sizeof(Student), maxCount, file);
    fclose(file);

    return (int)numRead;
}

// Number of records in the file, computed from its size
long countRecords(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    long size;

    if (file == NULL)
        return -1;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fclose(file);

    return size / (long)sizeof(Student);
}

// Direct access: jumps to record 'index' and reads only that one
int readRecord(const char *filename, int index, Student *student)
{
    FILE *file = fopen(filename, "rb");
    int ok;

    if (file == NULL)
        return 0;

    ok = fseek(file, index * (long)sizeof(Student), SEEK_SET) == 0 &&
         fread(student, sizeof(Student), 1, file) == 1;
    fclose(file);

    return ok;
}

// Direct access: overwrites record 'index' in place ("r+b" keeps the content)
int updateRecord(const char *filename, int index, const Student *student)
{
    FILE *file = fopen(filename, "r+b");
    int ok;

    if (file == NULL)
        return 0;

    ok = fseek(file, index * (long)sizeof(Student), SEEK_SET) == 0 &&
         fwrite(student, sizeof(Student), 1, file) == 1;
    fclose(file);

    return ok;
}

void displayStudent(const Student *s)
{
    printf("%-5d %-15s %-10.2f\n", s->id, s->name, s->weight);
}

void displayStructures(Student data[], int count)
{
    printf("\n%-5s %-15s %-10s\n", "ID", "Name", "Weight");
    printf("%-5s %-15s %-10s\n", "---", "---------------", "----------");

    for (int i = 0; i < count; i++)
        displayStudent(&data[i]);
}

int main(void)
{
    Student data[COUNT];
    Student student;
    int numRead;
    int index = 4;

    // Sequential access: write and read the whole array
    generateStructures(data, COUNT);
    if (!saveStructuresToFile(FILENAME, data, COUNT))
        return 1;

    numRead = readStructuresFromFile(FILENAME, data, COUNT);
    if (numRead < 0)
        return 1;
    displayStructures(data, numRead);

    printf("\nThe file has %ld records of %zu bytes each\n",
           countRecords(FILENAME), sizeof(Student));

    // Direct access: read one record by its position
    if (!readRecord(FILENAME, index, &student))
    {
        printf("Can not read record %d\n", index);
        return 1;
    }
    printf("\nRecord at position %d (counting from 0):\n", index);
    displayStudent(&student);

    // Direct access: modify that record in the file
    student.weight = 70.0f;
    if (!updateRecord(FILENAME, index, &student))
    {
        printf("Can not update record %d\n", index);
        return 1;
    }
    printf("\nAfter updating the weight of record %d:", index);

    numRead = readStructuresFromFile(FILENAME, data, COUNT);
    if (numRead < 0)
        return 1;
    displayStructures(data, numRead);

    return 0;
}
