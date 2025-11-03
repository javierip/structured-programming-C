#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure
typedef struct Student
{
    int id;
    char name[50];
    float weight;
} Student;

// Function to generate structures with sample data
void generateStructures(Student data[], int count)
{
    for (int i = 0; i < count; i++)
    {
        data[i].id = i + 1;
        sprintf(data[i].name, "Student %d", i + 1);
        data[i].weight = (float)rand() / RAND_MAX * 100.0; // Random value between 0 and 100
    }
}

// Function to save structures to a binary file
int saveStructuresToFile(const char *filename, Student data[], int count)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return 0; // Return 0 for failure
    }

    size_t written = fwrite(data, sizeof(Student), count, file);
    fclose(file);

    if (written != count)
    {
        fprintf(stderr, "Error writing data to file. Written %zu items\n", written);
        return 0; // Return 0 for failure
    }

    printf("%d structures generated and saved to %s\n", count, filename);
    return 1; // Return 1 for success
}

// Function to read structures from a binary file
int readStructuresFromFile(const char *filename, Student data[], int count)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return 0; // Return 0 for failure
    }

    size_t numRead = fread(data, sizeof(Student), count, file);
    fclose(file);

    if (numRead != count)
    {
        fprintf(stderr, "Error reading data from file. Read %zu items\n", numRead);
        return 0; // Return 0 for failure
    }

    return 1; // Return 1 for success
}

// Function to display structures
void displayStructures(Student data[], int count)
{
    printf("\nDisplaying %d structures:\n", count);
    printf("%-5s %-15s %-10s\n", "ID", "Name", "Value");
    printf("%-5s %-15s %-10s\n", "---", "---------------", "----------");

    for (int i = 0; i < count; i++)
    {
        printf("%-5d %-15s %-10.2f\n",
               data[i].id, data[i].name, data[i].weight);
    }
}

int main()
{
    const int COUNT = 10;
    const char *FILENAME = "data.bin";
    Student data[COUNT];

    // Generate structures with sample data
    generateStructures(data, COUNT);

    // Save the structures to a file
    if (!saveStructuresToFile(FILENAME, data, COUNT))
    {
        return 1;
    }

    // Read structures from the file
    if (!readStructuresFromFile(FILENAME, data, COUNT))
    {
        return 1;
    }

    // Display the data read from the file
    displayStructures(data, COUNT);

    return 0;
}
