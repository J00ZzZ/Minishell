/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:03:24 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/06 15:14:39 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lastlst(t_list *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}

// void		ft_addlst_back(t_list **lst, t_list *n)
// {
// 	t_list	*tmp;

// 	if (lst && n)
// 	{
// 		if (*lst)
// 		{
// 			tmp = ft_lastlst(*lst);
// 			tmp->next = n;
// 		}
// 		else
// 			*lst = n;
// 	}
// }

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	make_n(t_list **bufstr, char *str)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->str = str;
	new->next = NULL;
	while (*bufstr)
	{
		tmp = (*bufstr)->next;
		free((*bufstr)->str);
		free(*bufstr);
		*bufstr = tmp;
	}
	if (*str)
		*bufstr = new;
	else
	{
		free(str);
		free(new);
	}
}

void	clean_list(t_list **bufstr)
{
	int		i;
	int		k;
	t_list	*tmp;
	char	*str;

	if (!bufstr || !*bufstr)
		return ;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return ;
	tmp = ft_lastlst(*bufstr);
	i = -1;
	k = 0;
	while (tmp->str[++i])
	{
		if (tmp->str[i] == '\n')
			break ;
	}
	while (tmp->str[i++])
		str[k++] = tmp->str[i];
	str[k] = 0;
	make_n(bufstr, str);
}
