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
