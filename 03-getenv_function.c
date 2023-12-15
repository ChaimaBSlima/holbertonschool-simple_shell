#include "simple_shell.h"
/**
 * _getenv - get the environment of the command
 *
 * @name: the string to match with the key
 *
 * Return: value of the key (path)
 * or NULL if the name dosen't exist
 *
 * @attention - _getenv need a free
 *  bc value allocated without free
 */
char *_getenv(char *name)
{

	int i;
	char *temp, *key, *value;
	char *real_value;

	for (i = 0; environ && environ[i]; i++)
	{
		temp = strdup(environ[i]);
		key = strtok(temp, "=");
		if (strcmp(key, name) == 0)
		{
			real_value = strtok(NULL, "\n");
			if (real_value)
			{
				value = strdup(real_value);
				free(temp);
				return value;
			}
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
