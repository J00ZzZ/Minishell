#ifndef EXECUTION_H
# define EXECUTION_H

# include "../libft/libft.h"
# include "../minishell.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

void	execute_external_command(t_cmd *cmd, char **envp);
t_cmd	*parse_input(char *input);
int		is_builtin(t_cmd *cmd);
char	**execute_builtin(t_cmd *cmd, char **envp);

#endif