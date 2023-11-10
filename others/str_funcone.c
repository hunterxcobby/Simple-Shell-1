#include "shell.h"

/**
 * strlen_function - the length of astring.
 * @str:  the input string.
 *
 * Return: Length of string that was taken as an input
 */
int strlen_function(char *str)
{
	int len = 0;

	while (*str)
	{
		len++;
		str++;
	}

	return (len);
}
