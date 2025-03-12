/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 08:27:46 by harleyng          #+#    #+#             */
/*   Updated: 2025/03/05 21:27:39 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// Helper function to check if a variable name is valid
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

// Helper function to print all exported variables
static void print_exported_vars(char **envp)
{
    while (*envp)
    {
        ft_putstr_fd("declare -x ", STDOUT_FILENO);
        ft_putendl_fd(*envp, STDOUT_FILENO);
        envp++;
    }
}

// Helper function to add or update an environment variable
static void add_or_update_env_var(char *arg, char ***envp)
{
    char *equal_sign = ft_strchr(arg, '=');
    if (!equal_sign)
        return; // No value to set, ignore

    // Extract the variable name
    char *name = ft_substr(arg, 0, equal_sign - arg);
    if (!name)
        return;

    // Check if the variable name is valid
    if (!is_valid_variable_name(name))
    {
        ft_putstr_fd("minishell: export: `", STDERR_FILENO);
        ft_putstr_fd(name, STDERR_FILENO);
        ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
        free(name);
        return;
    }

    // Check if the variable already exists
    char **env = *envp;
    while (*env)
    {
        if (ft_strncmp(*env, name, equal_sign - arg) == 0 && (*env)[equal_sign - arg] == '=')
        {
            // Update the existing variable
            free(*env);
            *env = ft_strdup(arg);
            free(name);
            return;
        }
        env++;
    }

    // Add the new variable
    *env = ft_strdup(arg);
    (*envp)[env - *envp + 1] = NULL; // Null-terminate the array
    free(name);
}

char **builtin_export(char **args, char **envp)
{
    if (!args[1])
    {
        // No arguments, print all exported variables
        print_exported_vars(envp);
        return envp;
    }

    // Process each argument
    int i = 1;
    while (args[i])
    {
        add_or_update_env_var(args[i], &envp);
        i++;
    }

    return envp;
}
