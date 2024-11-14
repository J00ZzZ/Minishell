/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:50:42 by liyu-her          #+#    #+#             */
/*   Updated: 2023/11/21 19:00:38 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tpm;

	if (lst && new)
	{
		if (*lst)
		{
			tpm = ft_lstlast(*lst);
			tpm->next = new;
		}
		else
			*lst = new;
	}
}
