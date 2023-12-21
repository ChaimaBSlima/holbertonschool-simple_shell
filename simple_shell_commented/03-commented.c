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
	/* environ is an array of strings that ends with a NULL string 
	that's how we iterate it */

	for (i = 0; environ && environ[i]; i++)
	{
		/* storing a copy if the string for further modification */
		temp = strdup(environ[i]);
		/* split the key and the value using '=' delimiter */
		key = my_strtok(temp, "=");
		/* if we found the name with the right key */
		if (strcmp(key, name) == 0)
		{
			/* take it's value by cutting the value between the '=' and the next line */
			real_value = my_strtok(NULL, "\n");
			/* if the value isn't the null */
			if (real_value)
			{
				/* take a copy of it in a storing variable */
				value = strdup(real_value);
				free(temp);
				return (value);
			}
		}
		/* free the memory after using it */
		free(temp), temp = NULL;
	}
	return (NULL);
}
