#include "simple_shell.h"
/**
 * main - Entry point
 *
 * Return: 0
 *
 */
int main(void)
{
	char commands[120];

	while (1)
	{
		/*write(STDOUT_FILENO, "$", strlen("$"));*/
		read_command(commands, sizeof(commands));
		execute_command(commands);
	}
	free (commands);
	return (0);
}
