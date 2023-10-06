/* Program: Operations over an array of structures
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 81
#define TOTAL_STUDENTS 5

typedef struct
{
    char name[LINE_LENGTH];
    char surname[LINE_LENGTH];
    int  age;
} Person;


void printStudents(Person students[], int n );
void sortByAge( Person students[], int n );
void sortBySurname( Person students[], int n );


int main()
{
    Person studentsSet[TOTAL_STUDENTS] =
    {
        { "Dennis", "Ritchie", 79 },
        { "Alan", "Turing", 45 },
        { "Donald", "Knuth", 89 },
        { "John", "Von Neumann", 50 },
        { "Douglas", "Engelbert", 80 }
    };

    printf("Original list - ");
    printStudents(studentsSet, TOTAL_STUDENTS );

    printf("Sort by age - ");
    sortByAge(studentsSet, TOTAL_STUDENTS );
    printStudents(studentsSet, TOTAL_STUDENTS );

    printf("Sort by surname - ");
    sortBySurname(studentsSet, TOTAL_STUDENTS );
    printStudents(studentsSet, TOTAL_STUDENTS );

    return 0;
}

void printStudents(Person students[], int n)
{
    int i;

    printf("Famous students\n\n");
    for ( i=0; i<n; i++ )
        printf("%s, %s: age: %d\n",
               students[i].surname, students[i].name, students[i].age);

    printf("\n\n");
}

void sortByAge(Person students[], int n)
{
    Person temp;
    int i, j;

    for ( i=0; i<n; i++ )
    {
        for ( j=0; j<=n-2; j++ )
        {
            if ( students[j].age > students[j+1].age )
            {
                temp = students[j+1];
                students[j+1] = students[j];
                students[j] = temp;
            }
        }
    }
}

void sortBySurname(Person students[], int n)
{
    Person temp;
    int i, j;

    for (i=0; i<n; i++)
    {
        for (j=0; j<=n-2; j++)
        {
            if (strcmp(students[j].surname, students[j+1].surname) > 0)
            {
                temp = students[j+1];
                students[j+1] = students[j];
                students[j] = temp;
            }
        }
    }
}
