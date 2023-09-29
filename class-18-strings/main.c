/* Program: Simple code examples that use strings
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu.ar
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 80

void test_content(char string_1[], char *string_2)
{
    if (0 > strcmp(string_1, string_2))
        printf("first argument is lower\n");
    else if (0 < strcmp(string_1, string_2))
        printf("first argument is lower\n");
    else
        printf("Same content\n");

}

void test_concatenation(char string_1[], char *string_2, char *result)
{
    strcpy( result, "" );
    strcat( result, string_1 );
    strcat( result, " " );
    strcat( result, string_2 );
}
int main()
{
    char a_name[LINE_LENGTH] = "Jane";
    char another_name[LINE_LENGTH] = "Paul";
    char result_string[LINE_LENGTH];

    printf("Test content of different strings\n");
    test_content(a_name, another_name);

    printf("\nTest content of same string\n");
    test_content(a_name, a_name);

    printf("\nTest concatenation of same string\n");
    test_concatenation(a_name, another_name, result_string);
    printf("The resulting string is %s\n", result_string);

    return 0;
}
