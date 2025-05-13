/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:34:55 by harleyng          #+#    #+#             */
/*   Updated: 2025/02/27 09:35:02 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Frees an array of strings.
*/
#include "libft.h"

void	ft_arrfree(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}