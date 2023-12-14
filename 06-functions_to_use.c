#include "simple_shell.h"
/**
 * ConvertIntToStr - convert an integer to a string
 *
 * @n: the integer
 *
 * Return: a string
 *
 */
char *ConvertIntToStr(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (strdup(buffer));
}
/**
 * reverse_str - reverse a string
 *
 * @str: the string
 * @len: the length of the string
 *
 * Return: a string
 *
 */
void reverse_str(char *str, int len)
{
	char tmp;
	int starting = 0;
	int ending = len - 1;

	while (starting < ending)
	{
		tmp = str[starting];
		str[starting] = str[ending];
		str[ending] = tmp;
		starting++;
		ending--;
	}
}
