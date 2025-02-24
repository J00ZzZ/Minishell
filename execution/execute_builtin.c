#include "execution.h"
#include "../builtin/builtin.h"


int execute_builtin(char **args, char **envp)
{
    (void)envp;
    if (ft_strncmp(args[0], "echo", 4) == 0)
        return builtin_echo(args);
    // else if (ft_strcmp(args[0], "cd") == 0)
    //     return builtin_cd(args);
    // else if (ft_strcmp(args[0], "pwd") == 0)
    //     return builtin_pwd(args);
    // else if (ft_strcmp(args[0], "export") == 0)
    //     return builtin_export(args);
    // else if (ft_strcmp(args[0], "unset") == 0)
    //     return builtin_unset(args);
    // else if (ft_strcmp(args[0], "env") == 0)
    //     return builtin_env(args, envp);
    // else if (ft_strcmp(args[0], "exit") == 0)
    //     return builtin_exit(args);
    return (0); // Not a built-in command
}