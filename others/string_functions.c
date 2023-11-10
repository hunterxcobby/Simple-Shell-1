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
 * _strdup - Creates a duplicate of the input string.
 *
 * This function allocates memory for a new string and copies the contents of
 * the source string into it.
 *
 * @src: Pointer to the source string.
 *
 * Return: Pointer to the newly allocated duplicate string.
 */
char *_strdup(const char *src)
{
	int len, i;
	char *dst;

	if (src == NULL)
		return (NULL);

	len = _strlen_const(src);
	if (len < 0)
		return (NULL);

	len++;

	dst = malloc((len) * sizeof(char));
	if (dst == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dst[i] = src[i];

	dst[i - 1] = '\0';
	return (dst);
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

/**
 * strcmp_function - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return:
 *   - 0 if the strings are equal.
 *   - A negative value if s1 is less than s2.
 *   - A positive value if s1 is greater than s2.
 */
int strcmp_function(char *str1, char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}
