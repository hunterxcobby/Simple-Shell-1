#include "shell.h"

/* this is to print the erro message*/
void error(char *command)
{
    char *error_message;
    char *error_message2;
    
    error_message= "Command '";
    write(STDERR_FILENO, error_message, strlen_function(error_message));
    write(STDERR_FILENO, command, strlen_function(command));
    error_message2 = "' not found\n";
    write(STDERR_FILENO, error_message2, strlen_function(error_message2));
    exit(EXIT_FAILURE);

}


/**
 * execcp - Execute a command in a child process with full path.
 * @command: The command to execute.
 * @args: The arguments for the command.
 *
 * This function executes a command in a child process using the execve system
 * call. It handles errors related to executing the command and accessing the
 * command's executable file.
 */
void exec_cp(char *command, char *args[])
{
    char *path = find_path(command);

    if (path == NULL)
    {
        if (access(command, X_OK) == 0)
        {
            path = command;
        }
        else
        {
            error(command);
            _exit(EXIT_FAILURE);
        }
    }

    if (execve(path, args, NULL) == -1)
    {
        perror("execve");
    }

    free(path);

    _exit(EXIT_FAILURE);
}