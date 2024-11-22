#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

// Define the structure
typedef struct MyStruct
{
    int id;
    char name[50];
    float value;
} MyStruct;

int main()
{
    // Generate 10 structures
    MyStruct data[10];
    for (int i = 0; i < 10; i++)
    {
        data[i].id = i + 1;
        strcpy(data[i].name, "Structure ");
        // Add the ID as a character to the name
        data[i].name[strlen(data[i].name)] = i + '1';
        data[i].name[strlen(data[i].name)] = '\0';      // Null-terminate the string
        data[i].value = (float)rand() / RAND_MAX * 100; // Random value between 0 and 100
    }

    // Save the structures to a file
    FILE *file = fopen("data.bin", "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fwrite(data, sizeof(MyStruct), 10, file);

    fclose(file);
    printf("10 structures generated and saved to data.bin\n");

    file = fopen("data.bin", "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Read 10 structures from the file
    // size_t numRead = fread(data, sizeof(MyStruct), 10, file);
    unsigned long numRead = fread(data, sizeof(MyStruct), 10, file);

    if (numRead != 10)
    {
        fprintf(stderr, "Error reading data from file. Read %zu items\n", numRead);
    }
    else
    {
        // Print the data read from the file
        for (int i = 0; i < 10; i++)
        {
            printf("ID: %d, Name: %s, Value: %.2f\n",
                   data[i].id, data[i].name, data[i].value);
        }
    }

    fclose(file);

    return 0;
}
