#include "execution.h"

char **parse_input(char *input)
{
    char **args = NULL;
    char *token;
    int i = 0;

    // Split input into tokens
    token = ft_strtok(input, " ");
    while (token)
    {
        args = realloc(args, (i + 1) * sizeof(char *));
        args[i] = ft_strdup(token);
        token = ft_strtok(NULL, " ");
        i++;
    }

    // Null-terminate the array≠
    args = realloc(args, (i + 1) * sizeof(char *));
    args[i] = NULL;

    return args;
}