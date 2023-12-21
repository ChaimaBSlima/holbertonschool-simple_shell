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
	/* The  isatty() function tests whether
	 fd is an open file descriptor referring to a terminal. */
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	/* getline to read inputs and allocate it */
	n = getline(&line, &len, stdin);
	/* getline return (-1) if it's EOF */
	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	/* return the line inputed */
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
	/* condition if the line = NULL */
	if (!line)
		return (NULL);
	/* storing a copy of line in tmp bc I want to make some modification 
	without losing the value of it */
	tmp = strdup(line);
	/* taking the first word in the line */
	token = my_strtok(tmp, DELIM);
	/* codition: if  token is NULL*/
	if (token == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	/* increaming i = calculate how words we have */
	while (token)
	{
		i++;
		token = my_strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	/* allocate memory for all the words with (+1) a NULL place for the iteration */
	commands = malloc(sizeof(char *) * (i + 1));
	/* condtion: if the allocation failed */
	if (!commands)
	{
		free(line), line = NULL;
		return (NULL);
	}
	/* take the first command now to store it in the array of strings */
	token = my_strtok(line, DELIM);
	while (token)
	{
		/* storing in the array named commands */
		commands[j] = strdup(token);
		token = my_strtok(NULL, DELIM);
		j++;
	}
	/* free allocated memory */
	free(line), line = NULL;
	/* last word take NULL*/
	commands[j] = NULL;
	/* return the array of string */
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
	/* creating a pid_t variable to store our frok value*/
	pid_t child_pid;
	int status;
	/* handeling the path of our command */
	the_real_command = _getpath(commands[0]);
	/* if the command not found: print this error and exit with 127 status */
	if (!the_real_command)
	{
		PrintNotFoundError(argv[0], commands[0], index);
		freestring(commands);
		return (127);
	}

	/* creating a child process */
	child_pid = fork();
	/* if we are in the child excute this part of code */
	if (child_pid == 0)
	{
		/* execeve return -1 on failure but it works then stops the code 
		that's why we need a copy of thr process */
		if (execve(the_real_command, commands, env) == -1)
		{
			free(the_real_command), the_real_command = NULL;
			freestring(commands);
		}
	}
	/* excuting the parent process */
	else
	{
		/* wait for the child excution then free allocated memory */
		waitpid(child_pid, &status, 0);
		freestring(commands);
		free(the_real_command), the_real_command = NULL;
	}
	/* return the status to the exit */
	return (WEXITSTATUS(status));
}
