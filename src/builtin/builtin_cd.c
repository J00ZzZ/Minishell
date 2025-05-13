/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:22:48 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/13 22:08:45 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Get the value of an environment variable
static char	*get_env_value(char **envp, const char *key)
{
	int	i;
	int	key_len;

	key_len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, key_len) == 0 && envp[i][key_len] == '=')
			return (envp[i] + key_len + 1);
		i++;
	}
	return (NULL);
}

// Helper function to get the target path for cd
static char	*get_cd_path(char **args, char **envp)
{
	char	*path;

	if (!args[1] || ft_strncmp(args[1], "~", 2) == 0)
	{
		path = get_env_value(envp, "HOME");
		if (!path)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = get_env_value(envp, "OLDPWD");
		if (!path)
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
		else
			ft_putendl_fd(path, 1);
	}
	else
		path = args[1];
	return (path);
}

// Helper function to update PWD and OLDPWD
static char	**update_pwd_vars(char **envp, const char *oldpwd)
{
	char	cwd[PATH_MAX];

	envp = update_env_var(envp, "OLDPWD", oldpwd);
	if (!envp)
		return (NULL);
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("minishell: cd");
		return (envp);
	}
	envp = update_env_var(envp, "PWD", cwd);
	return (envp);
}

// Main cd builtin function
char	**builtin_cd(char **args, char **envp)
{
	char *path;
	char oldpwd[PATH_MAX];

	path = get_cd_path(args, envp);
	if (!path)
		return (envp);
	if (getcwd(oldpwd, PATH_MAX) == NULL)
	{
		perror("minishell: cd");
		return (envp);
	}
	if (chdir(path) == -1)
	{
		perror("minishell: cd");
		return (envp);
	}
	return (update_pwd_vars(envp, oldpwd));
}