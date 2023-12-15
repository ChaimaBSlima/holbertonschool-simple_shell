#include "simple_shell.h"
/**
 * _getpath - get the path of the command
 * from  the environment
 *
 * @command: the command to handle
 *
 * Return: the path of the command or
 * itself if it is a path
 *
 */
char *_getpath(char *command)
{

	char *the_path, *the_real_command, *directory;
	struct stat state;
	int i;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &state) == 0)
				return (strdup(command));
			return (NULL);
		}
	}
	the_path = _getenv("PATH");
	if (the_path == NULL)
		return (NULL);
	directory = strtok(the_path, ":");
	while (directory)
	{
		the_real_command = malloc(strlen(directory) + strlen(command) + 2);
		if (the_real_command)
		{
			strcpy(the_real_command, directory);
			strcat(the_real_command, "/");
			strcat(the_real_command, command);
			if (stat(the_real_command, &state) == 0)
			{
				free(the_path);
				return (the_real_command);
			}
			free(the_real_command);
			the_real_command = NULL;
			directory = strtok(NULL, ":");
		}
		else
		{
			return (NULL);
		}
	}
	free(the_path);
	return (NULL);
}
