#include "shell.h"

void prompt(void);

/**
 * main - Entry point of the shell program.
 * Return: Always returns 0.
 */
int main(void)
{
	char *path, *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;
	int result;

	while (1)
	{
		prompt(); /* display the shell prompt */
		read_size = getline(&input, &input_size, stdin); /* read user input */
		if (read_size == -1)
		{
			free(input);
			return (0); /* exit loop and program on input failure */
		}
		if (input[read_size - 1] == '\n')
			input[read_size - 1] = '\0'; /* remove trailing newline */
		/* check if the user wants to exit the shell */
		if (strncmp_function(input, "exit", 4) == 0)
		{
			free(input);
			input = NULL;
			input_size = 0;
			exit(EXIT_SUCCESS); /* exit the shell gracefully */
		}
		/* check if the user wants to print environment variables */
		if (strcmp_function(stmstr_function(input), "env") == 0)
		{
			print_env(); /* print environment variables */
			continue;
		}
		if (strncmp_function(input, "cd", 2) == 0)
		{
			path = stmstr_function(input + 2); /* Remove 'cd' from the input */
			cd_function(path);
			free(input);
			input = NULL;
			input_size = 0;
			continue;
		}
		if (read_size > 1) /* Execute the command and handle errors */
		{
			result = execute_command(stmstr_function(input));
			if (result == -1)
				break;
		}
	}
	free(input);
	return (0);
}
