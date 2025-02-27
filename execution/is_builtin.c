/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:19:15 by harleyng          #+#    #+#             */
/*   Updated: 2025/02/27 10:19:47 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
int	is_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (ft_strncmp(args[0], "cd", 3) == 0 ||
		ft_strncmp(args[0], "echo", 5) == 0 ||
		ft_strncmp(args[0], "pwd", 4) == 0 ||
		ft_strncmp(args[0], "export", 7) == 0 ||
		ft_strncmp(args[0], "unset", 6) == 0 ||
		ft_strncmp(args[0], "env", 4) == 0 ||
		ft_strncmp(args[0], "exit", 5) == 0)
		return (1);
	return (0);
}