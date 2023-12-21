#include "simple_shell.h"
/**
 * main - Entry point
 *
 * @argc: number of arguments
 * @argv: the arguments
 * @env: envirenment
 *
 * Return: 0
 *
 */
int main(int argc, char **argv, char **env)
{
	/* initialise arrays and matrix on NULL to avoid memory problemes*/
	char *line = NULL;
	char **commands = NULL;
	/* initialise status to handel the status (echo $?) */
	/* index needed while printing errors*/
	int status = 0, index = 0;
	/* unseful paramater*/
	(void)argc;
	/* signal to handel advanced task ctr + C */
	signal(SIGINT, sigint_handler);
	/* entering the loop */
	while (1)
	{
		/* reading inputs */
		line = read_line();
		/* condition end of file : EOF 
		 read_line return NULL if it's EOF */
		if (line == NULL)
		{
			/* The  isatty() function tests whether
			 fd is an open file descriptor referring to a terminal. */
			if (isatty(STDIN_FILENO))
			{
				/* print new line then exit shell*/
				write(STDOUT_FILENO, "\n ", 1);
			}
			/* returning status , exiting loop */
			return (status);
		}
		/* increaming index */
		index++;
		/* split the input based on space tab and new line */
		commands = read_command(line);
		/* if the user typed nothing continue ($)*/
		if (!commands)
			continue;
		/* handeling builtin exit and env */
		if (strcmp("exit", commands[0]) == 0)
			exit_shell(commands, argv, &status, index);
		else if (strcmp("env", commands[0]) == 0)
			print_env(commands, &status);
		else
		/* execute the command if it's otherwise */
			status = execute_command(commands, argv, env, index);
	}
}
