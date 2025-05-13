/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:28:41 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/11 03:29:29 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_envp_len(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}

char	**copy_envp(char **envp)
{
	int		i;
	char	**my_env;

	i = 0;
	if (!envp)
		return (NULL);
	my_env = malloc((ft_envp_len(envp) + 1) * sizeof(char *));
	if (!my_env)
		return (NULL);
	while (envp[i])
	{
		my_env[i] = ft_strdup(envp[i]);
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}
