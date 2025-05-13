/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 09:13:18 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/11 03:26:13 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_valid_tok(t_token *token_root)
{
	t_token	*token;

	token = token_root;
	if (!token)
		return (1);
	if (token->type == TOKEN_PIPE)
		return (0);
	while (token)
	{
		if (token->openend)
			return (0);
		if (token->type == TOKEN_PIPE)
		{
			if (!token->next || token->next->type == TOKEN_PIPE)
				return (0);
		}
		else if (token->type == TOKEN_IN_REDIR || token->type == TOKEN_OUT_REDIR
			|| token->type == TOKEN_APPEND || token->type == TOKEN_HEREDOC)
		{
			if (!token->next || token->next->type != TOKEN_WORD)
				return (0);
		}
		token = token->next;
	}
	return (1);
}

int	ft_valid(t_token *token_root)
{
	t_token	*token;
	int		heredocid;

	if (!token_root)
		return (0);
	token = token_root;
	if (!ft_valid_tok(token_root))
		return (0);
	heredocid = -1;
	while (token)
	{
		if (is_heredoc(token) && token->fhere_doc == NULL)
			if (!input_heredoc(token, ++heredocid))
			{
				printf("heredoc failed\n");
				return (0);
			}
		token = token->next;
	}
	return (1);
}
