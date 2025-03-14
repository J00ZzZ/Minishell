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
char	**builtin_pwd(char **args, char **envp);
char	**builtin_exit(char **args, char **envp);
char	**builtin_env(char **args, char **envp);
char	**builtin_export(char **args, char **envp);
char	**builtin_unset(char **args, char **envp);
char	**update_env_var(char **envp, const char *key, const char *value);

#endif