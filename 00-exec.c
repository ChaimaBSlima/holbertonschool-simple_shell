#include "simple_shell.h"
/**
 * main - Entry point
 *
 * @argc: number of arguments
 * @argv: the arguments
 * @env: envirenment
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	char **commands = NULL;
	int status = 0, index = 0;
	(void)argc;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n ", 1);
			}
			return (status);
		}
		index++;
		commands = read_command(line);
		if (!commands)
			continue;

		if (strcmp("exit", commands[0]) == 0)
			exit_shell(commands, argv, &status, index);
		else if (strcmp("env", commands[0]) == 0)
			print_env(commands, &status);
		else
			status = execute_command(commands, argv, env, index);


	}
}
