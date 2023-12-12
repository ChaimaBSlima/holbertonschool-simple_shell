#include "simple_shell.h"
/**
 * freestring - a function that frees array of strings
 *
 * @str : the array of strings
 *
 * Return: void
 */
void freestring(char **str)
{
	int i;

	if (!str)
		return;
	for (i = 0; str[i]; i++)
	{
		free(str[i]);
		str[i] = NULL;
	}
	free(str);
	str = NULL;
}
