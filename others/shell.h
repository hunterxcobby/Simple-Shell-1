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
int strlen_function(const char *str);
int strcmp_function(char *str1, char *str2);
char *strdup_function(const char *str);
char *strcpy_function(char *dest, const char *source);
char *strncpy_function(char *dest, const char *source, int num);
int strncmp_function(const char *str1, const char *str2, size_t num);
char *_strcat(char *dest, char *src);
char *_strtrim(char *str);
char *get_path(char *command);


/* Other functions*/
void cd_function(char *path);
char *_getenv(const char *name);
int execute_command(char *command_with_args);
void execute_child_process(char *command, char *args[]);
void print_environment(void);
void prompt(void);


#endif
