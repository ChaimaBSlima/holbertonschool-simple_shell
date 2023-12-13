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
/* extern char **environ */

/*functions execute_commands.c */
char *read_line(void);
char **read_command(char *line);
int execute_command(char **commands, char **argv, char **env);

/* functions free_functions.c*/
void freestring(char **str);

#endif /* __SIMPLE__SHELL__ */
