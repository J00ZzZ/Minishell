/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:22:48 by harleyng          #+#    #+#             */
/*   Updated: 2025/03/03 07:27:27 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static char	**update_env_var(char **envp, const char *key, const char *value)
{
	int		i;
	char	*temp;
	char	*new_var;
	char	**new_envp;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (NULL);
	new_var = ft_strjoin(temp, value);
	free(temp);
	if (!new_var)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0
			&& envp[i][ft_strlen(key)] == '=')
		{
			free(envp[i]);
			envp[i] = new_var;
			return (envp);
		}
		i++;
	}
	// If the variable doesn't exist, add it to the environment
	new_envp = malloc((i + 2) * sizeof(char *));
	if (!new_envp)
	{
		free(new_var);
		return (NULL);
	}
	i = 0;
	while (envp[i])
	{
		new_envp[i] = envp[i];
		i++;
	}
	new_envp[i] = new_var;
	new_envp[i + 1] = NULL;
	free(envp);
	return (new_envp);
}
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


char	**builtin_cd(char **args, char **envp)
{
	char	*path;
	char	cwd[PATH_MAX];
	char	oldpwd[PATH_MAX];

	if (!args[1] || ft_strncmp(args[1], "~", 2) == 0)
	{
		path = get_env_value(envp, "HOME");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (envp);
		}
	}
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = get_env_value(envp, "OLDPWD");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (envp);
		}
		// When using cd -, print the directory we're moving to
		ft_putendl_fd(path, 1);
	}
	else
		path = args[1];
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
