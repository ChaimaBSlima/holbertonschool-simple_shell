#include "simple_shell.h"
/**
 * exit_shell - exit the shell
 * handle the exit function
 *
 * @command: the exit command
 * @argv: argv[0] needed
 * @status: the staus
 * @index: the index
 *
 * Return: void
 *
 */
void exit_shell(char **command, char **argv, int *status, int index)
{
	int exit_value = (*status);

	if (command[1])
	{
		if (atoi(command[1]) > 0)
			exit_value = atoi(command[1]);
		else
		{
			PrintIllegalNumberError(argv[0], command[1], index);
			freestring(command);
			(*status) = 2;
			return;
		}
	}

	freestring(command);
	exit(exit_value);
}
/**
 * print_env - print the environment
 * handle the env function
 *
 * @command: the exit command
 * @status: the status
 *
 * Return: void
 *
 */
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freestring(command);
	(*status) = 0;
}
/**
 * change_directory - change the directory
 *
 * @commands: array of strings
 * @status: the status
 * @index: the index
 * @argv: argv[0] needed
 *
 * Return: status
 *
 */
void change_directory(char **cmd, int *status, int idx, char **av)
{
	(*status) = 0;
	if (cmd[1] == NULL) 
	{
        if (chdir(_getenv("HOME")) == -1)
        {
            PrintCantCdToError(av[0], cmd[1], idx);
            (*status) = 2; 
        }
        else
        {
            (*status) = 139;
        }
	}
	else
	{
		if (chdir(cmd[1]) == -1)
		{
			 PrintCantCdToError(av[0], cmd[1], idx);
			(*status) = 0;
		}
	}
	freestring(cmd);
}
