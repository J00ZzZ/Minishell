/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:24:14 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/13 22:08:59 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char **builtin_pwd(char **args, char **envp)
{
    char cwd[PATH_MAX];
    
    (void)args; // Unused parameter
    
    if (getcwd(cwd, PATH_MAX) == NULL)
    {
        perror("minishell: pwd");
        return envp;
    }
    
    ft_putendl_fd(cwd, STDOUT_FILENO);
    return envp;
}
