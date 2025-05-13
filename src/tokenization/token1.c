/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:46:06 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/11 03:30:50 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_openend(t_token *token)
{
	while (token)
	{
		while (token->next && token->openend == 1)
		{
			tk_comb_next(token);
			if (token->value[0] == token->value[ft_strlen(token->value) - 1]
				&& ft_strlen(token->value) > 1)
			{
				token->openend = 0;
			}
		}
		token = token->next;
	}
}

void	ft_quotes(t_token *token)
{
	char	quote;

	while (token)
	{
		if (token && ft_strchr("'\"", *token->value)
				&& ft_strlen(token->value) == 1)
		{
			quote = *token->value;
			while (token->next && *token->next->value != quote)
				tk_comb_next(token);
			if (!token->next)
				token->openend = 1;
			tk_comb_next(token);
		}
		token = token->next;
	}
}

void	ft_double(t_token *token)
{
	while (token && token->next)
	{
		if (token->type != TOKEN_SPACE && token->type != TOKEN_PIPE)
		{
			if (token->type == token->next->type)
			{
				tk_comb_next(token);
				if (token->type == TOKEN_OUT_REDIR)
					token->type = TOKEN_APPEND;
				else if (token->type == TOKEN_IN_REDIR)
					token->type = TOKEN_HEREDOC;
			}
			else if (token->type == TOKEN_OUT_REDIR
				&& token->next->type == TOKEN_PIPE)
				tk_comb_next(token);
		}
		token = token->next;
	}
}

void	ft_word(t_token *token)
{
	while (token && token->next)
	{
		if (token->type == TOKEN_WORD && token->next->type == TOKEN_WORD
			&& !token->next->openend)
			tk_comb_next(token);
		else
			token = token->next;
	}
}

void	clean_token(t_token *token_root)
{
	t_token	*token;

	token = token_root;
	ft_openend(token);
	ft_quotes(token);
	ft_tokentype(token);
	ft_rmvspace(token);
	ft_double(token);
	ft_word(token);
	ft_word(token);
	ft_combspce(token);
	while (token)
	{
		printf("final: %s, type: %d, openend: %d\n", token->value, token->type,
			token->openend);
		token = token->next;
	}
}
