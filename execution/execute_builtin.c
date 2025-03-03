#include "execution.h"
#include "../builtin/builtin.h"

char	**execute_builtin(char **args, char **envp)
{
    if (ft_strncmp(args[0], "echo", 4) == 0)
        return builtin_echo(args, envp);
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		return (builtin_cd(args, envp));
	else if (ft_strncmp(args[0], "pwd", 3) == 0)
        return builtin_pwd(args, envp);
	else if (ft_strncmp(args[0], "export", 6) == 0)
		return builtin_export(args, envp);
	else if (ft_strncmp(args[0], "unset", 5) == 0)
		return builtin_unset(args, envp);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		return builtin_env(args, envp);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		return builtin_exit(args, envp);
	return (envp);
}