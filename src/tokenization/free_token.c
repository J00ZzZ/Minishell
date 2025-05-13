/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:57:59 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/07 02:27:09 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void ft_freetoken(t_token *token_root)
{
    t_token *rmv;

    while (token_root)
    {
        rmv = token_root;
        token_root = token_root->next;
        if (rmv->fhere_doc)
            free(rmv->fhere_doc);
        free(rmv->value);
        free(rmv);
    }
}