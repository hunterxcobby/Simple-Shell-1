#include "shell.h"

/**
 * strcpy_function - Copy the contents of the source string
 * to the destination string.
 * @dest: The destination string.
 * @source: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *strcpy_function(char *dest, const char *source)
{
	char *orig_dest;

	if (dest == NULL || source == NULL)
		return (NULL);

	orig_dest = dest;

	while ((*dest++ = *source++))
		;

	return (orig_dest);
}

/**
 * _strncpy - copies string
 * @dest: string 1 value
 * @src: string 2 value
 * @n: size
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}


