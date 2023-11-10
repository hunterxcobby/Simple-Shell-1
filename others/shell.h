#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
#define MAX_INPUT_LEN 1024

/* String functions*/
int strlen_function(char *str);
int strcmp_function(char *str1, char *str2);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *_strtrim(char *str);
char *get_path(char *command);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Other functions*/
void cd_function(char *path);
char *_getenv(const char *name);
int execute_command(char *command_with_args);
void execute_child_process(char *command, char *args[]);
void print_environment(void);
void prompt(void);


#endif
