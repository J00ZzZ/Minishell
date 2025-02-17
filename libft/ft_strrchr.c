/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:06:03 by hang              #+#    #+#             */
/*   Updated: 2023/11/01 19:23:51 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (s[slen] == (char)c)
			return ((char *)&s[slen]);
		if (slen == 0)
			return (0);
		slen--;
	}
	return (0);
}
