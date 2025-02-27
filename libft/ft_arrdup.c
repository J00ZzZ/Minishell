/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:33:04 by harleyng          #+#    #+#             */
/*   Updated: 2025/02/27 09:33:05 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Duplicates an array of strings.
*/
#include "libft.h"

char	**ft_arrdup(char **arr)
{
	int i;
	char **new_arr;

	i = 0;
	while (arr[i])
		i++;
	new_arr = malloc((i + 1) * sizeof(char *));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
		{
			while (i--)
				free(new_arr[i]);
			free(new_arr);
			return (NULL);
		}
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}