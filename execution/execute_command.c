#include "execution.h"

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h" // Include your libft header

static char	*find_executable(char *cmd, char *path)
{
	char	*dir;
	char	*full_path;
	char	*path_copy;

	path_copy = ft_strdup(path); // Use ft_strdup from libft
	if (!path_copy)
		return (NULL);
	dir = ft_strtok(path_copy, ":"); // Use ft_strtok from libft
	while (dir)
	{
		full_path = ft_strjoin(dir, "/");
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		full_path = ft_strjoin(full_path, cmd);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		if (access(full_path, X_OK) == 0) // Check if executable exists
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path); // Free if not executable
		dir = ft_strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL); // Executable not found
}

static void	execute_child(char **args, char **envp)
{
	char	*path;
	char	*full_path;

	// If the command is an absolute path, skip PATH search
	if (ft_strchr(args[0], '/')) // Use ft_strchr from libft
	{
		if (access(args[0], X_OK) == 0) // Check if executable exists
		{
			execve(args[0], args, envp); // Execute the command
			perror("minishell"); // If execve fails
			exit(1);
		}
		else
		{
			ft_printf("minishell: %s: command not found\n", args[0]); // Use ft_printf_fd from libft
			exit(1);
		}
	}

	// Search for PATH in envp
	path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0) // Use ft_strncmp from libft
		{
			path = *envp + 5; // Skip "PATH=" to get the actual path
			break;
		}
		envp++;
	}
	if (!path) // PATH not found
	{
		ft_printf("minishell: PATH not set\n"); // Use ft_printf_fd from libft
		exit(1);
	}
	full_path = find_executable(args[0], path); // Find executable in PATH
	if (!full_path) // Executable not found
	{
		ft_printf("minishell: %s: command not found\n", args[0]); // Use ft_printf_fd from libft
		exit(1);
	}
	execve(full_path, args, envp); // Execute the command
	perror("minishell"); // If execve fails
	free(full_path);
	exit(1);
}

void	execute_command(char **args, char **envp)
{
	pid_t	pid;

	pid = fork(); // Fork the process
	if (pid == 0) // Child process
		execute_child(args, envp);
	else if (pid > 0) // Parent process
		wait(NULL); // Wait for the child to finish
	else // Fork failed
		perror("minishell");
}
