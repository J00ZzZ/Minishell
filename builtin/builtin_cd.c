#include "builtin.h"

static char	**update_env_var(char **envp, const char *key, const char *value)
{
	int		i;
	char	*new_var;
	char	**new_envp;

	new_var = ft_strjoin(key, "=");
	new_var = ft_strjoin(new_var, value);
	if (!new_var)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], key, ft_strlen(key)) == 0 && envp[i][ft_strlen(key)] == '=')
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

/*
** Built-in: cd
** Changes the current working directory.
** Returns the updated envp array.
*/
char	**builtin_cd(char **args, char **envp)
{
	char	*path;
	char	cwd[PATH_MAX];
	char	oldpwd[PATH_MAX];

	if (!args[1] || ft_strncmp(args[1], "~", 2) == 0)
	{
		path = getenv("HOME");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (envp);
		}
	}
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = getenv("OLDPWD");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
			return (envp);
		}
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
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		perror("minishell: cd");
		return (envp);
	}
	envp = update_env_var(envp, "PWD", cwd);
	return (envp);
}
