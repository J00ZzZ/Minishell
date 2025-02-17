/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:10:26 by hang              #+#    #+#             */
/*   Updated: 2023/11/10 22:49:52 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	total_len;

	if (dst == NULL && dstsize == 0)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	total_len = dst_len + src_len;
	if (!dst && !dstsize)
		return (src_len);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] && dst_len < dstsize - 1)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (total_len);
}
