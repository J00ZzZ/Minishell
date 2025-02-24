/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:40:01 by harleyng          #+#    #+#             */
/*   Updated: 2025/02/24 07:40:27 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	is_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strtok(char *str, const char *delim)
{
	static char	*save_ptr;
	char		*token_start;

	if (str)
		save_ptr = str;
	while (*save_ptr && is_delim(*save_ptr, delim))
		save_ptr++;
	if (!*save_ptr)
		return (NULL);
	token_start = save_ptr;
	while (*save_ptr && !is_delim(*save_ptr, delim))
		save_ptr++;
	if (*save_ptr)
	{
		*save_ptr = '\0';
		save_ptr++;
	}
	return (token_start);
}
