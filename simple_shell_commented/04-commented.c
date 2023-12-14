#include "simple_shell.h"
/**
 * _getpath - get the path from
 * the environment of the command
 *
 * @name: the string to much with key
 *
 * Return: value of the key (path)
 *
 * @attention - _getenv need a free
 *  bc value allocated without free
 */
char *_getpath(char *command)
{

    char *the_path;
    char *the_real_command;
    char *directory;
    struct stat state;
    int i;


    /*A loop if the command is already a path (not a command)*/
    for (i = 0; command[i]; i++)
    {
        if (command[i] == '/')
        {
            if (stat(command, &state) == 0)
            {
                /* using strdup to escape handeling the free of
                the variable command */
                return (strdup(command));
            }
            return (NULL);
        }
    }

    the_path = _getenv("PATH");
    /* A condition if the user unset the PATH 
    * we can not access directory at this condition
    */
    if (!the_path)
        return (NULL);
    /* handeling the path */
    directory = strtok(the_path, ":");
    while (directory)
    {
        /* directory size + command size +2 bc ('/' and '\0') */
        the_real_command = malloc(strlen(directory) + strlen(command) + 2);
        if (the_real_command)
        {
            strcpy(the_real_command, directory);
            strcat(the_real_command, "/");
            strcat(the_real_command, command);
            if (stat(the_real_command, &state) == 0)
            {
                free(the_path);
                return (the_real_command);
            }
            free(the_real_command);
            the_real_command = NULL;
            directory = strtok(NULL, ":");
        }
    }
    free(the_path);
    return (NULL);
}
int main(int ac, char **av)
{
    char *cmd;
    cmd = _getpath(av[1]);
    if (cmd)
    {
        printf("%s\n", cmd);
    }
    else
    {
        printf("d n't exist\n");
    }
}