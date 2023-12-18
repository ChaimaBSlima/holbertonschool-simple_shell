#ifndef __SIMPLE__SHELL__
#define __SIMPLE__SHELL__

/* include libraries to use */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Define constants */
#define DELIM " \t\n"
extern char **environ;

/* functions of file : 01-execute_commands.c */
char *read_line(void);
char **read_command(char *line);
int execute_command(char **commands, char **argv, char **env, int index);

/* functions of file 02-free_functions.c */
void freestring(char **str);

/* prototype from file 03-getenv_function.c */
char *_getenv(char *name);

/* prototype from file 04-getpath_function.c */
char *_getpath(char *command);

/* functions of file 05-errors_functions.c */
void PrintNotFoundError(char *shellname, char *typed_command, int index);
void PrintIllegalNumberError(char *shellname, char *typed_command, int index);

/* functions of file 06-functions_to_use.c */
char *ConvertIntToStr(int n);
void reverse_str(char *str, int len);

/* functions of file 07-functions_builtin.c */
void exit_shell(char **command, char **argv, int *status, int index);
void print_env(char **command, int *status);

/* functions of file 08-my_strtok.c */
char *my_strtok(char *str, const char *delim);

#endif /* __SIMPLE__SHELL__ */
