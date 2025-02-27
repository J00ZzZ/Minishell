#include "execution.h"
#include "../builtin/builtin.h"

char	**execute_builtin(char **args, char **envp)
{
    // if (ft_strncmp(args[0], "echo", 4) == 0)
    //     return builtin_echo(args);
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (builtin_cd(args, envp));
	// Handle other built-in commands here
	return (envp);
}