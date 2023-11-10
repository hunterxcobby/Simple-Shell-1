#include "shell.h"


/**
 * _strlen_const - Calculates the length of a null-terminated string.
 * @s: Pointer to the input string.
 *
 * Return: Length of the string.
 */

int _strlen_const(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
 * _strcat - concatenate two strings
 * @dest: char string to be concatenated to.
 * @src: char string
 * Return: concatenated string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

