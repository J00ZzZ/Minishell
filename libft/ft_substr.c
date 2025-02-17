/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 03:00:04 by hang              #+#    #+#             */
/*   Updated: 2023/11/18 14:12:49 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lencheck(char const *s, unsigned int start, size_t len)
{
	if (((size_t)ft_strlen(s) - start) < len)
	{
		return (((size_t)ft_strlen(s) - start));
	}
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	subs = (char *)malloc(sizeof(char) * (ft_lencheck(s, start, len) + 1));
	if (!subs)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		subs[i] = s[start];
		start++;
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
