#include "shell.h"

/**
 * execute_command - Execute a command with arguments in a child process.
 * @command_with_args: The command with its arguments.
 *
 * This function forks a child process to execute the given command along with
 * its arguments using the execve system call. It handles errors related to
 * forking, executing the command, and accessing the command's executable file.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command_with_args)
{
    pid_t child_pid;
    int status;
    char *token, *args[MAX_INPUT_LEN / 2 + 2];
    int arg_count = 0;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        return -1;
    }

    if (child_pid == 0) 
    {
        token = strtok(command_with_args, " ");

        while (token != NULL && arg_count < MAX_INPUT_LEN / 2 + 1)
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }

        args[arg_count] = NULL;

        exec_cp(args[0], args);
    }
    else 
    {
        wait(&status);
    }

    return 0;
}
