/* Program: Sort a matrix of strings
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu.ar
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TOTAL_NAMES 4
#define LINE_LENGTH 81

void insertion_sort( char nom[][LINE_LENGTH], int n );
void print_data( const char *titulo, const char nom[][LINE_LENGTH], int n );

int main()
{
    char data_container[TOTAL_NAMES][LINE_LENGTH] = {
        "Bill Gates", "Larry Page",	"Steve Jobs", "Mark Zukerberg"
    };

    print_data( "Unsorted names", data_container, TOTAL_NAMES );
    insertion_sort( data_container, TOTAL_NAMES );
    print_data( "Sorted names", data_container, TOTAL_NAMES );

    return 0;
}

void print_data( const char* message, const char data[][LINE_LENGTH], int n )
{
    int i;

    puts( message );
    for (i = 0; i < strlen( message ); i++)
        putchar( '-' );
    puts( "" );

    for (i = 0; i < n; i++)
        puts( data[i] );

    puts( "" ); puts( "" );
}

void insertion_sort( char data[][LINE_LENGTH], int n )
{
    int pass = 1;
    char temp[LINE_LENGTH];
    int j;

    for (pass = 1; pass < n; pass++)
    {
        strcpy( temp, data[pass] );

        j = pass - 1;
        while (j >= 0 && strcmp( temp, data[j] ) < 0) {
            strcpy( data[j + 1], data[j] );
            j--;
        }

        strcpy( data[j + 1], temp );
    }
}
