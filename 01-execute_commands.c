#include "simple_shell.h"
/**
 * read_line - reading input from the user
 *
 * Return: string value
 *
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
/**
 * read_command - Read commands from user
 *
 * @line: the line of commands
 *
 * Return: array of strings
 *
 */
char **read_command(char *line)
{
	char *token = NULL;
	char **commands = NULL;
	char *tmp = NULL;
	int i = 0;
	int j = 0;

	if (!line)
		return (NULL);
	tmp = strdup(line);
	token = my_strtok(tmp, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = my_strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	commands = malloc(sizeof(char *) * (i + 1));
	if (!commands)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = my_strtok(line, DELIM);
	while (token)
	{
		commands[j] = strdup(token);
		token = my_strtok(NULL, DELIM);
		j++;
	}
	free(line), line = NULL;
	commands[j] = NULL;
	return (commands);
}
/**
 * execute_command - excute the commands typed
 *  by the user
 *
 * @commands: the commands
 * @argv: the arguments
 * @env: envirenment for execve
 * @index: number of commands typed
 *
 * Return: status value
 *
 */
int execute_command(char **commands, char **argv, char **env, int index)
{

	char *the_real_command;
	pid_t child_pid;
	int status;

	the_real_command = _getpath(commands[0]);
	if (!the_real_command)
	{
		PrintNotFoundError(argv[0], commands[0], index);
		freestring(commands);
		return (127);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(the_real_command, commands, env) == -1)
		{
			free(the_real_command), the_real_command = NULL;
			freestring(commands);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		freestring(commands);
		free(the_real_command), the_real_command = NULL;
	}
	return (WEXITSTATUS(status));
}
