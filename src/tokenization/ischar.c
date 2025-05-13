/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ischar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:06:23 by liyu-her          #+#    #+#             */
/*   Updated: 2025/04/29 22:55:26 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int is_here_doc(t_token *token)
{
    if (!token || !token->prev || token->type != TOKEN_WORD)
        return (0);
    token = token->prev;
    while (token && token->type == TOKEN_SPACE)
        token = token->prev;
    if (token && token->type == TOKEN_HEREDOC)
        return (1);
    return (0);
}

int is_meta(char input)
{
    if(ft_strchr(C_META, input))
        return (1);
    return (0);
}

int is_quote(char input)
{
    if (ft_strchr(C_QUOTE, input))
        return (1);
    return (0);
}

int is_ban_char(char input)
{
    if (ft_strchr(C_BAN, input))
        return (1);
    return(0);
}