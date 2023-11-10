#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */
char *strdup_function(const char *str)
{
    char *dup; /* The duplicate string*/
    size_t len;
    if (str == NULL)
        return (NULL);

    len = strlen_function(str);
    dup = (char *)malloc(len + 1);

    if (dup == NULL)
        return NULL;

    strcpy(dup, str);
    return (dup);
}