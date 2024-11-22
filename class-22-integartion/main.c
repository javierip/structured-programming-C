/* Program: Linked list example
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to  save the linked list to a file
void saveLinkedList(Node *head, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        // Write the data of the current node to the file
        fwrite(&current->data, sizeof(int), 1, file);
        current = current->next;
    }

    fclose(file);
}

// Function to print the content of the linked list
void printLinkedList(Node *head)
{
    Node *current = head;
    printf("Linked list: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;    // Store the current node temporarily
        current = current->next; // Move to the next node
        free(temp);              // Free the memory of the previous node
    }
}

// Function to load the linked list from a file
Node *loadLinkedList(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }

    Node *head = NULL;
    Node *tail = NULL;
    int data;

    // Read data from the file until the end of file is reached
    while (fread(&data, sizeof(int), 1, file) == 1)
    {
        // Create a new node
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL)
        {
            perror("Memory allocation failed");
            fclose(file); // Close the file before returning
            return NULL;
        }
        newNode->data = data;
        newNode->next = NULL;

        // If the list is empty, set the new node as head
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Append the new node to the end of the list
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}

// Example usage
int main()
{
    // Create a sample linked list
    Node *head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Save the linked list to a file
    saveLinkedList(head, "linked_list.dat");
    printf("Linked list saved to file.\n");

    printLinkedList(head);

    freeLinkedList(head);
    head = 0;

    // Load the linked list from the file
    printf("Linked list loaded from file.\n");
    Node *loadedList = loadLinkedList("linked_list.dat");
    printLinkedList(loadedList);
    freeLinkedList(loadedList);
    loadedList = 0;

    return 0;
}