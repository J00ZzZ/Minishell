/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:14:11 by liyu-her          #+#    #+#             */
/*   Updated: 2023/11/21 17:33:56 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

static int	word_count(char const *str, char set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], set))
			i++;
		if (str[i] && !is_sep(str[i], set))
			count++;
		while (str[i] && !is_sep(str[i], set))
			i++;
	}
	return (count);
}

static char	*fill_letters(char const *str, char set)
{
	char	*newstr;
	int		i;

	i = 0;
	while (!is_sep(str[i], set) && str[i])
		i++;
	newstr = (char *)malloc((i + 1) * sizeof(char));
	if (!newstr)
		return (0);
	i = 0;
	while (!is_sep(str[i], set) && str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	**ft_split(char const *s, char set)
{
	char	**split_str;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	count = word_count(s, set);
	split_str = (char **)malloc((count + 1) * sizeof(char *));
	if (!split_str)
		return (0);
	while (*s)
	{
		while (*s && is_sep(*s, set))
			s++;
		if (*s)
		{
			split_str[i] = fill_letters(s, set);
			i++;
			while (*s && !is_sep(*s, set))
				s++;
		}
	}
	split_str[i] = 0;
	return (split_str);
}
