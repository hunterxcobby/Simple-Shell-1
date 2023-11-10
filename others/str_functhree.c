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
 * strncpy_function - Copy up to n characters from source to destination.
 * @dest: The destination string.
 * @source: The source string.
 * @num: The maximum number of characters to copy.
 *
 * Return: A pointer to the destination string.
 */
char *strncpy_function(char *dest, const char *source, int num)
{
	char *orig_dest = dest;

	while (num > 0 && *source)
	{
		*dest = *source;
		dest++;
		source++;
		num--;
	}

	while (num > 0)
	{
		*dest = '\0';
		dest++;
		num--;
	}

	return (orig_dest);
}


