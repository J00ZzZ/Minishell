/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:19:15 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/13 22:09:17 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int is_builtin(t_cmd *cmd)
{
    if (!cmd || !cmd->command)
        return (0);

    if (ft_strncmp(cmd->command, "cd", 3) == 0 ||
        ft_strncmp(cmd->command, "echo", 5) == 0 ||
        ft_strncmp(cmd->command, "pwd", 4) == 0 ||
        ft_strncmp(cmd->command, "export", 7) == 0 ||
        ft_strncmp(cmd->command, "unset", 6) == 0 ||
        ft_strncmp(cmd->command, "env", 4) == 0 ||
        ft_strncmp(cmd->command, "exit", 5) == 0)
        return (1);

    return (0);
}
