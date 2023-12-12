#include "simple_shell.h"
/**
 * main - Entry point
 *
 * Return: 0
 *
 */
int main(void)
{
	char *commands ;

	while (1)
	{
		/*write(STDOUT_FILENO, "$", strlen("$"));*/
		read_command(commands, sizeof(commands));
		execute_command(commands);
	}

	return (0);
}
