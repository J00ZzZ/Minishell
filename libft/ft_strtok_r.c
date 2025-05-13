/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:11:17 by harleyng          #+#    #+#             */
/*   Updated: 2025/03/13 09:11:30 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *token;

    if (str)
        *saveptr = str; // Initialize saveptr if a new string is provided

    // Skip leading delimiters
    *saveptr += strspn(*saveptr, delim);

    if (**saveptr == '\0')
        return NULL; // No more tokens

    // Find the end of the token
    token = *saveptr;
    *saveptr = token + strcspn(token, delim);

    if (**saveptr != '\0')
    {
        **saveptr = '\0'; // Null-terminate the token
        (*saveptr)++;     // Move saveptr to the next character
    }

    return token;
}