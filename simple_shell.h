#ifndef __SIMPLE__SHELL__
#define __SIMPLE__SHELL__

/* include libraries to use */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/*functions*/
void execute_command(const char *command);
void read_command(char *command, size_t size);

#endif /* __SIMPLE__SHELL__ */
