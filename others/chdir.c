#include "shell.h"

/**
 * cd_function - Change current directory.
 * @path: The path .
 */
void cd_function(char *path)
{
	char *new_dir;

	if (!path || *path == '\0')
		path = getenv("HOME");
	else if (strcmp_function(path, "-") == 0)
		path = getenv("OLDPWD");

	if (chdir(path) != 0)
	{
		perror("chdir");
		return;
	}

	new_dir = getcwd(NULL, 0);

	if (new_dir != NULL)
	{
		setenv("PWD", new_dir, 1);
		free(new_dir);
	}
	else
	{
		perror("change directory failed");
	}
}
