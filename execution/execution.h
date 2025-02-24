#ifndef EXECUTION_H
# define EXECUTION_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void    execute_command(char **args, char **envp);
int     execute_builtin(char **args, char **envp);
char    **parse_input(char *input);

#endif