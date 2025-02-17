/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:58:22 by hang              #+#    #+#             */
/*   Updated: 2023/11/10 22:45:49 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	len;

	if (s1 == NULL && s2 == NULL)
		return (0);
	len = 0;
	if (s2 < s1)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((char *)s1)[len] = ((char *)s2)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((char *)s1)[len] = ((char *)s2)[len];
			len++;
		}
	}
	return (s1);
}
