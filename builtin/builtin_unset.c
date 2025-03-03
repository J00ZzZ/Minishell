/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:31:46 by harleyng          #+#    #+#             */
/*   Updated: 2025/03/03 08:33:14 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"    

static int is_valid_variable_name(const char *name)
{
    if (!name || !*name)
        return 0;

    // Variable names must start with a letter or underscore
    if (!ft_isalpha(*name) && *name != '_')
        return 0;

    // Check the rest of the name
    while (*name)
    {
        if (!ft_isalnum(*name) && *name != '_')
            return 0;
        name++;
    }
    return 1;
}

// Helper function to remove a variable from the envp array
static void remove_env_var(const char *name, char ***envp)
{
    char **env = *envp;
    while (*env)
    {
        // Check if the current environment variable matches the name
        if (ft_strncmp(*env, name, ft_strlen(name)) == 0 && (*env)[ft_strlen(name)] == '=')
        {
            // Free the memory for the variable
            free(*env);

            // Shift the remaining elements to fill the gap
            char **next = env + 1;
            while (*next)
            {
                *env = *next;
                env++;
                next++;
            }
            *env = NULL; // Null-terminate the array
            return;
        }
        env++;
    }
}

char **builtin_unset(char **args, char **envp)
{
    if (!args[1])
    {
        // No arguments, do nothing
        return envp;
    }

    // Process each argument
    int i = 1;
    while (args[i])
    {
        if (!is_valid_variable_name(args[i]))
        {
            // Print an error message for invalid variable names
            ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
            ft_putstr_fd(args[i], STDERR_FILENO);
            ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
        }
        else
        {
            // Remove the variable from the envp array
            remove_env_var(args[i], &envp);
        }
        i++;
    }

    return envp;
}