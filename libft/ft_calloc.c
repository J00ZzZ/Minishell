/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:18:19 by liyu-her          #+#    #+#             */
/*   Updated: 2023/11/18 22:38:45 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ji;

	if (size && UINT_MAX / size < count)
		return (NULL);
	ji = malloc(count * size);
	if (!ji)
		return (NULL);
	ft_bzero(ji, count * size);
	return (ji);
}
