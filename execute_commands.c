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
	token = strtok(line, DELIM);
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	commands = malloc(sizeof(char *) * (i + 1));
	if (!commands)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		commands[j] = strdup(token);
		token = strtok(NULL, DELIM);
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
 * Return: Void
 *
 */
int execute_command(char **commands, char **argv)
{

	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
		{
			perror(argv[0]);
			freestring(commands);
			exit(0);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		freestring(commands);
	}
	return (WEXITSTATUS(status));
}
