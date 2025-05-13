/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:55:32 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/08 09:13:25 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_combspce(t_token *token)
{
	while (token && token->next)
	{
		if (token->value && token->next->type == TOKEN_SPACE
			&& !token->next->openend)
			tk_comb_next(token);
		else
			token = token->next;
	}
}


void	ft_rmvspace(t_token *token)
{
	while (token && token->next)
	{
		if (token->type == TOKEN_SPACE)
		{
			while (token->next && token->next->type == TOKEN_SPACE)
				token_remove(token->next);
		}
		token = token->next;
	}
}

void	token_remove(t_token *token)
{
	t_token	*prev;
	t_token	*next;

	if (!token)
		return ;
	prev = token->prev;
	next = token->next;
	free(token->value);
	free(token);
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
}

void	tk_comb_next(t_token *token)
{
	char	*new_value;

	if (!token || !token->next)
		return ;
	new_value = ft_strjoin(token->value, token->next->value);
	if (!new_value)
		perr_exit("malloc", EXIT_FAILURE);
	free(token->value);
	token->value = new_value;
	token_remove(token->next);
}
