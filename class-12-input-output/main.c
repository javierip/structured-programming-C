/* Program: Read until a selected char in detected
 * Author: Javier Iparraguirre
 * E-mail: jiparraguirre@frbb.utn.edu
 * Original source form https://cplusplus.com/reference/cstdio/getchar/
 */

#include <stdio.h>

int main()
{
	int user_input;
	puts("Enter text. Include a dot ('.') in a sentence to exit:");
	do
	{
		user_input = getchar();
		putchar(user_input);
	} while (user_input != '.');

	return 0;
}