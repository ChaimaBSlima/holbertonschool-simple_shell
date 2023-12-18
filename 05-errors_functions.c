#include "simple_shell.h"
/**
 * PrintNotFoundError - print the not found error
 *
 * @shellname: the shell name
 * @typed_command: the wrong typed command
 * @index: number of commands
 *
 * Return: void
 *
 */
void PrintNotFoundError(char *shellname, char *typed_command, int index)
{
	char *index_str;

	index_str = ConvertIntToStr(index);
	write(STDERR_FILENO, shellname, strlen(shellname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index_str, strlen(index_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, typed_command, strlen(typed_command));
	write(STDERR_FILENO, ": not found\n", strlen(": not found\n"));
	free(index_str);
}
/**
 * PrintIllegalNumberError - print the not found error
 *
 * @shellname: the shell name
 * @typed_command: the wrong typed command
 * @index: number of commands
 *
 * Return: void
 *
 */
void PrintIllegalNumberError(char *shellname, char *typed_command, int index)
{
	char *index_str;
	int len = strlen(": exit: Illegal number: ");

	index_str = ConvertIntToStr(index);
	write(STDERR_FILENO, shellname, strlen(shellname));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index_str, strlen(index_str));
	write(STDERR_FILENO, ": exit: Illegal number: ", len);
	write(STDERR_FILENO, typed_command, strlen(typed_command));
	write(STDERR_FILENO, "\n", 1);

	free(index_str);
}

