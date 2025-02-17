/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:55:24 by hang              #+#    #+#             */
/*   Updated: 2023/11/17 15:05:42 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytes;
	void	*p;

	if (size > 0 && count > UINT_MAX / size)
		return (0);
	bytes = count * size;
	p = malloc(bytes);
	if (!p)
		return (NULL);
	else
		ft_bzero(p, bytes);
	return (p);
}

// check if arguments is not zero
// check if count * size is not too large for malloc