#include "simple_shell.h"
/**
 * read_command - Read commands from user
 *
 * @command: command from the user
 * @size: size of the command
 * Return: Void
 *
 */
void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", strlen("\n"));
			exit(EXIT_SUCCESS);
		}
		else
		{
			write(STDOUT_FILENO, "Error while reading input.\n",
			 strlen("Error while reading input.\n"));
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
/**
 * execute_command - excute the commands typed
 *  by the user
 *
 * @command: command type by the user
 * Return: Void
 *
 */
void execute_command(const char *command)
{

	__pid_t child_pid = fork();

	if (child_pid == -1)
	{
		write(STDOUT_FILENO, "Error forking process.\n",
		 strlen("Error forking process.\n"));
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{

		char *args[128];
		int arg_count = 0;
		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;


		execvp(args[0], args);

		write(STDOUT_FILENO, "Error executing command.\n",
		strlen("Error executing command.\n"));
		exit(EXIT_FAILURE);
	}
	/*else
	{
		wait(NULL);
	}*/
}
