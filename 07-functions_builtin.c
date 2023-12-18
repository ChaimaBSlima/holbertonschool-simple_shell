#include "simple_shell.h"
/**
 * exit_shell - exit the shell
 * handle the exit function
 *
 * @command: the exit command
 * @status: the staus
 *
 * Return: void
 *
 */
void exit_shell(char **command, int *status)
{
	freestring(command);
	exit(*status);
}

/**
 * print_env - print the environment
 * handle the env function
 *
 * @command: the exit command
 * @status: the staus
 *
 * Return: void
 *
 */
void print_env(char **command, int *status)
{
	int i;

	(void)status;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freestring(command);
	(*status) = 0;
}
