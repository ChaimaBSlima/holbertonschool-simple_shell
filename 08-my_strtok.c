#include "simple_shell.h"

/**
 * my_strtok - split a string
 *
 * @str: the string
 * @delim: the delimiter
 *
 * Return: the string before (between) the delimiter
 *
 */

char *my_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *tokenEnd;

	if (str == NULL && lastToken != NULL)
		str = lastToken;

	if (str == NULL || *str == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	str += strspn(str, delim);
	if (*str == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	tokenEnd = str + strcspn(str, delim);
	if (*tokenEnd != '\0')
	{
		*tokenEnd = '\0';
		lastToken = tokenEnd + 1;
	}
	else
	{
		lastToken = NULL;
	}

	return (str);
}

