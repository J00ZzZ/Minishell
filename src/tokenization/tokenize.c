/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:50:13 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/13 12:15:39 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_tokenadd_back(t_token **token_ptr, t_token *new)
{
	t_token	*head;

	if (!*token_ptr)
	{
		*token_ptr = new;
		return ;
	}
	head = *token_ptr;
	while (head->next)
		head = head->next;
	head->next = new;
	new->prev = head;
}

t_token	*ft_new_token(char *value)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = value;
	return (token);
}

t_token	*input_to_token(char *start, int len)
{
	t_token	*token;
	char	*value;

	value = ft_substr(start, 0, len);
	if (!value)
		perr_exit("malloc", 1);
	token = ft_new_token(value);
	if (!token)
	{
		free(value);
		perr_exit("malloc", 1);
	}
	return (token);
}

t_token	*inputoken(char *input)
{
	t_token	*token_ptr;
	t_token	*token;
	char	*start;

	token_ptr = NULL;
	while (*input)
	{
		if (!is_meta(*input))
		{
			start = input;
			while (*input && !is_meta(*input))
				input++;
			token = input_to_token(start, input - start);
		}
		else
		{
			token = input_to_token(input, 1);
			input++;
		}
		ft_tokenadd_back(&token_ptr, token);
	}
	return (token_ptr);
}

t_token	*ft_tokenization(char *input, t_token *token_root)
{
	t_token	*tokens;

	if (!input || ft_strlen(input) == 0)
		return (token_root);
	tokens = inputoken(input);
	ft_tokenadd_back(&token_root, tokens);
	clean_token(token_root);
	if (!ft_valid(token_root))
	{
		ft_freetoken(token_root);
		return (NULL);
	}
	return (tokens);
}
