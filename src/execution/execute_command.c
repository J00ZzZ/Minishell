#include "../../inc/minishell.h"

static char	*find_full_path(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin_three(paths[i++], "/", cmd);
		if (access(full_path, X_OK) == 0)
			return full_path;
		free(full_path);
	}
	return NULL;
}

static char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;

	if (!cmd || !envp || ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return ft_strdup(cmd);
		return NULL;
	}

	paths = ft_split(getenv("PATH"), ':');
	if (!paths)
		return NULL;

	full_path = find_full_path(paths, cmd);
	ft_arrfree(paths);
	return full_path;
}


static void	handle_redirect(char *file, int flags, int std_fd)
{
	int	fd;

	if (!file)
		return ;
	fd = open(file, flags, 0644);
	if (fd == -1)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	dup2(fd, std_fd);
	close(fd);
}

void	execute_external_command(t_cmd *cmd, char **envp)
{
	char	*full_path;
	pid_t	pid;

	full_path = get_path(cmd->command, envp);
	if (!full_path)
		return (ft_putstr_fd("minishell: command not found\n", 2));
	pid = fork();
	if (pid == -1)
		return (perror("minishell"), free(full_path));
	if (pid == 0)
	{
		handle_redirect(cmd->input_redirect, O_RDONLY, STDIN_FILENO);
		handle_redirect(cmd->output_redirect, O_WRONLY | O_CREAT | O_TRUNC,
			STDOUT_FILENO);
		execve(full_path, cmd->args, envp);
		perror("minishell");
		free(full_path);
		exit(EXIT_FAILURE);
	}
	free(full_path);
}
