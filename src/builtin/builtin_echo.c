/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:01:14 by harleyng          #+#    #+#             */
/*   Updated: 2025/05/13 22:08:47 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char **builtin_echo(char **args, char **envp)
{
    int i = 1;
    int newline = 1; // Default to printing a newline

    // Check for the -n option(s)
    if (args[1] != NULL)
    {
        // Check if args[1] starts with "-n" and contains only 'n' characters
        if (args[1][0] == '-' && args[1][1] == 'n')
        {
            int j = 2;
            while (args[1][j] == 'n')
                j++;
            
            // If it's just -n or -nnn... (all n's), treat as -n
            if (args[1][j] == '\0')
            {
                newline = 0;
                i++; // Skip the -n argument
            }
        }
    }

    // Print the remaining arguments
    while (args[i] != NULL)
    {
        ft_putstr_fd(args[i], 1);  // Use direct file descriptor output
        if (args[i + 1] != NULL)
            ft_putstr_fd(" ", 1);
        i++;
    }

    // Print a newline unless -n is specified
    if (newline)
        ft_putstr_fd("\n", 1);
    
    return envp;  // Return environment unchanged
}