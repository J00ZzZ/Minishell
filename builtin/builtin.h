#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	**builtin_echo(char **args, char **envp);
char	**builtin_cd(char **args, char **envp);
int		builtin_pwd(char **args);
int		builtin_export(char **args);
int		builtin_unset(char **args);
int		builtin_env(char **args);
int		builtin_exit(char **args);

#endif