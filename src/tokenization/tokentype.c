/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokentype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 01:02:58 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/11 03:30:27 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_tokentype(t_token *token)
{
	while (token)
	{
		if (is_meta(*token->value) && ft_strlen(token->value) == 1)
		{
			if (*token->value == '>')
				token->type = TOKEN_OUT_REDIR;
			else if (*token->value == '<')
				token->type = TOKEN_IN_REDIR;
			else if (*token->value == '|')
				token->type = TOKEN_PIPE;
			else if (*token->value == ' ')
				token->type = TOKEN_SPACE;
		}
		else if (is_ban_char(*token->value) && ft_strlen(token->value) == 1)
			token->type = 258;
		token = token->next;
	}
}
