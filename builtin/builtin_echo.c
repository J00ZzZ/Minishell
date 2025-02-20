# include "builtin.h"

int builtin_echo(char **args)
{
    int i = 1;
    int newline = 1; // Default to printing a newline

    // Check for the -n option
    if (args[1] != NULL && ft_strncmp(args[1], "-n", 2) == 0)
    {
        newline = 0;
        i++; // Skip the -n argument
    }

    // Print the remaining arguments
    while (args[i] != NULL)
    {
        ft_printf("%s", args[i]);
        if (args[i + 1] != NULL)
            ft_printf(" ");
        i++;
    }

    // Print a newline unless -n is specified
    if (newline)
        ft_printf("\n");
    return (0);
}
