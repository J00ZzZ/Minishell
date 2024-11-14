/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:04:11 by liyu-her          #+#    #+#             */
/*   Updated: 2023/11/22 16:34:36 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	size_t			count;
	size_t			real;

	if (!s)
		return (NULL);
	count = ft_strlen(s);
	real = count;
	if ((size_t)start >= count || len == 0)
		return (ft_strdup(""));
	i = 0;
	if (count > len)
		real = len;
	str = (char *)malloc(sizeof(char) * (real + 1));
	if (!str)
		return (0);
	while ((size_t)i < real && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
