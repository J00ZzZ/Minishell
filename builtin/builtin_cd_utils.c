#include "builtin.h"

// Create the key=value string for the environment variable
static char	*create_env_var(const char *key, const char *value)
{
	char	*temp;
	char	*new_var;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (NULL);
	new_var = ft_strjoin(temp, value);
	free(temp);
	return (new_var);
}

// Replace an existing environment variable in the envp array
static char	**replace_env_var(char **envp, char *new_var, const char *key)
{
	int	i;

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
	return (NULL);
}

// Add a new environment variable to the envp array
static char	**add_env_var(char **envp, char *new_var)
{
	int		i;
	char	**new_envp;

	i = 0;
	while (envp[i])
		i++;
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

// Update or add an environment variable
char	**update_env_var(char **envp, const char *key, const char *value)
{
	char	*new_var;
	char	**result;

	new_var = create_env_var(key, value);
	if (!new_var)
		return (NULL);
	result = replace_env_var(envp, new_var, key);
	if (result)
		return (result);
	return (add_env_var(envp, new_var));
}
