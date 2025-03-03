/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:13:48 by harleyng          #+#    #+#             */
/*   Updated: 2025/03/03 08:17:13 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char **builtin_exit(char **args, char **envp)
{
    (void)envp; // Unused parameter

    if (args[1] == NULL)
    {
        // No arguments, exit with status 0
        exit(0);
    }
    else if (args[2] != NULL)
    {
        // More than one argument, print error and return
        ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
        return envp;
    }
    else
    {
        // Check if the argument is a valid number
        char *arg = args[1];
        while (*arg)
        {
            if (!ft_isdigit(*arg) && *arg != '-' && *arg != '+')
            {
                ft_putendl_fd("minishell: exit: numeric argument required", STDERR_FILENO);
                exit(2);
            }
            arg++;
        }

        // Convert the argument to an integer and exit
        int status = ft_atoi(args[1]);
        exit(status);
    }
    return envp; // This line is never reached
}