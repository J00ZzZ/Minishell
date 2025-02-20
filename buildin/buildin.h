#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

int builtin_echo(char **args);
int builtin_cd(char **args);
int builtin_pwd(char **args);
int builtin_export(char **args);
int builtin_unset(char **args);
int builtin_env(char **args);
int builtin_exit(char **args);
int execute_builtin(char **args);

#endif