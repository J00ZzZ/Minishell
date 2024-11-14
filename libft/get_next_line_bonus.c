/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:37:38 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/06 15:14:32 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_letter(t_list *bufstr, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * len + 2);
	if (!str)
		return (NULL);
	len = 0;
	while (bufstr)
	{
		i = -1;
		while (bufstr->str[++i])
		{
			str[len] = bufstr->str[i];
			len++;
			if (bufstr->str[i] == '\n')
				break ;
		}
		bufstr = bufstr->next;
	}
	str[len] = '\0';
	return (str);
}

char	*get_line(t_list *bufstr)
{
	int		count;
	t_list	*tmp;
	int		i;
	int		len;

	count = ft_lstsize(bufstr);
	tmp = ft_lastlst(bufstr);
	i = -1;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '\n')
			break ;
	}
	len = BUFFER_SIZE * (count - 1) + i;
	return (fill_letter(bufstr, len));
}

int	get_nwl(t_list **bufstr)
{
	t_list	*tmp;
	int		i;

	tmp = *bufstr;
	while (tmp)
	{
		i = -1;
		while (tmp->str[++i])
		{
			if (tmp->str[i] == '\n')
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	create_list(int fd, t_list **bufstr)
{
	char	*str;
	size_t	buf;
	t_list	*tmp;

	while (!get_nwl(bufstr))
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return ;
		buf = read(fd, str, BUFFER_SIZE);
		if (!buf)
		{
			free(str);
			return ;
		}
		str[buf] = 0;
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->str = str;
		tmp->next = 0;
		ft_lstadd_back(bufstr, tmp);
	}
}

char	*get_next_line(int fd)
{
	char			*str;
	static t_list	*bufstr[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &str, 0) < 0)
		return (NULL);
	create_list(fd, &bufstr[fd]);
	if (bufstr[fd] == NULL)
		return (NULL);
	str = get_line(bufstr[fd]);
	clean_list(&bufstr[fd]);
	return (str);
}
