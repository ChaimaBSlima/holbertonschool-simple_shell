#include "simple_shell.h"
/**
 * 
 * main : Entry point
 * 
 * 
 * 
*/
int main (void){
	char commands[100];
	while(1){
		write(STDOUT_FILENO, "$", strlen("$"));
		read_command(commands, sizeof(commands));
        execute_command(commands);

	}
	return (0);
}