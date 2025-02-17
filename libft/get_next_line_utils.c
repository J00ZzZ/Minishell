/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:02:14 by hang              #+#    #+#             */
/*   Updated: 2024/07/24 21:02:23 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cleanline(char *fd_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!fd_str[i])
		return (NULL);
	while (fd_str[i] && fd_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (fd_str[i] && fd_str[i] != '\n')
	{
		str[i] = fd_str[i];
		i++;
	}
	if (fd_str[i] == '\n')
	{
		str[i] = fd_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*delete_upto_nl(char *fd_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (fd_str[i] && fd_str[i] != '\n')
		i++;
	if (!fd_str[i])
	{
		free(fd_str);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(fd_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (fd_str[i])
		str[j++] = fd_str[i++];
	str[j] = '\0';
	free(fd_str);
	return (str);
}
