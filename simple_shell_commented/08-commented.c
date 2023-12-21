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
    /* Static variable to store the state across function calls */
    static char *lastToken;

    /* If str is NULL and there's a lastToken, continue from the last token */
    if (str == NULL && lastToken != NULL)
        str = lastToken;

    /* If str is NULL or an empty string, reset lastToken and return NULL */
    if (str == NULL || *str == '\0')
    {
        lastToken = NULL;
        return (NULL);
    }

    /* Skip leading delimiters */
    str += strspn(str, delim);

    /* If the remaining string is empty, reset lastToken and return NULL */
    if (*str == '\0')
    {
        lastToken = NULL;
        return (NULL);
    }

    /* Find the end of the current token */
    char *tokenEnd = str + strcspn(str, delim);

    /* If the token is not at the end of the string, terminate it and update lastToken */
    if (*tokenEnd != '\0')
    {
        *tokenEnd = '\0';
        lastToken = tokenEnd + 1;
    }
    else
    {
        /* If the token is at the end of the string, reset lastToken */
        lastToken = NULL;
    }

    /* Return a pointer to the current token */
    return (str);
}

