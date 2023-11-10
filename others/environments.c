#include "shell.h"

/**
 * print_env - Print all environment variables.
 *
 * This function prints all environment variables along with their values.
 */
void print_env(void)
{
    char **env;

    if (environ == NULL)
    {
        write(STDOUT_FILENO, "Environment variables are not set.\n", 36);
        return;
    }

    for (env = environ; *env != NULL; env++)
    {
        write(STDOUT_FILENO, *env, strlen_function(*env));
        write(STDOUT_FILENO, "\n", 1);
    }
}
