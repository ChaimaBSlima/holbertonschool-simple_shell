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

	/* A loop if the command is already a path (not a command) */
	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			/* stat to display file or file system status. */
			if (stat(command, &state) == 0)
			 /* using strdup to escape handeling the free of
                the variable command */
				return (strdup(command));
			return (NULL);
		}
	}
	the_path = _getenv("PATH");
	/* A condition if the user unset the PATH 
    * we can not access directory at this condition
    */
	if (the_path == NULL || the_path[0] == '\0')
		return (NULL);
	/* handeling the path with ':' delemiter  */
	directory = my_strtok(the_path, ":");
	while (directory)
	{
		/* directory size + command size +2 bc ('/' and '\0') */
		the_real_command = malloc(strlen(directory) + strlen(command) + 2);
		/* if the malloc succeded */
		if (the_real_command)
		{
			/* copy the the directory we got in the_real_command variable */
			strcpy(the_real_command, directory);
			/* add '/' to it */
			strcat(the_real_command, "/");
			/* add the command to it */
			strcat(the_real_command, command);
			/* try this path if it's exist in the sytem*/
			if (stat(the_real_command, &state) == 0)
			{
				/* if yes return it */
				free(the_path);
				return (the_real_command);
			}
			free(the_real_command);
			the_real_command = NULL;
			/* else : try another directory (path)*/
			directory = my_strtok(NULL, ":");
		}
	}
	free(the_path);
	return (NULL);
}
