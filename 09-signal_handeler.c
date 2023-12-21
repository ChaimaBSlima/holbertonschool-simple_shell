#include "simple_shell.h"
/**
 * sigint_handler - a function to not quit
 *  when the user inputs ^C
 *
 * @i: unuseful paramater but the
 *  signal functioj takes a function with int paramater
 * as a parameter
 *
 * Return: Void
 *
 */
void sigint_handler(int i)
{
	(void)i;

	write(STDOUT_FILENO, "\n$ ", 3);
}
