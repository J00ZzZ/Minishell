#ifndef EXECUTION_H
# define EXECUTION_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

void	execute_command(char **args, char **envp);
char	**execute_builtin(char **args, char **envp);
char	**parse_input(char *input);
int		is_builtin(char **args);

#endif