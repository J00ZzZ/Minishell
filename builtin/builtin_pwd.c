/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 07:24:14 by harleyng          #+#    #+#             */
/*   Updated: 2025/03/03 07:24:19 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

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