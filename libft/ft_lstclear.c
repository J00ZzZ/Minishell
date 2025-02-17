/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:06:16 by hang              #+#    #+#             */
/*   Updated: 2023/11/19 18:44:42 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (lst == NULL || del == NULL)
		return ;
	head = *lst;
	while (head)
	{
		head = head->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = head;
	}
}
