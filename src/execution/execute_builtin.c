#include "../../inc/minishell.h"

char **execute_builtin(t_cmd *cmd, char **envp)
{
    if (ft_strncmp(cmd->command, "echo", 4) == 0)
        return builtin_echo(cmd->args, envp);
    else if (ft_strncmp(cmd->command, "cd", 3) == 0)
        return builtin_cd(cmd->args, envp);
    else if (ft_strncmp(cmd->command, "pwd", 3) == 0)
        return builtin_pwd(cmd->args, envp);
    else if (ft_strncmp(cmd->command, "export", 6) == 0)
        return builtin_export(cmd->args, envp);
    else if (ft_strncmp(cmd->command, "unset", 5) == 0)
        return builtin_unset(cmd->args, envp);
    else if (ft_strncmp(cmd->command, "env", 4) == 0)
        return builtin_env(cmd->args, envp);
    else if (ft_strncmp(cmd->command, "exit", 5) == 0)
        return builtin_exit(cmd->args, envp);
    return (envp); // Return the environment if no built-in is matched
}
