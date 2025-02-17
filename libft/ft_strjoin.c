/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:49:34 by hang              #+#    #+#             */
/*   Updated: 2023/11/10 23:25:39 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		counter;
	int		i;
	int		bytes;

	if (s1 == NULL || s2 == NULL)
		return (0);
	counter = 0;
	bytes = 0;
	i = 0;
	bytes = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * bytes + 1);
	if (!str)
		return (0);
	while (s1[counter])
		str[i++] = s1[counter++];
	counter = 0;
	while (s2[counter])
		str[i++] = s2[counter++];
	str[i] = '\0';
	return (str);
}
