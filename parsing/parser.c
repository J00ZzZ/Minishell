/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:34:24 by liyu-her          #+#    #+#             */
/*   Updated: 2025/02/25 10:02:33 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_token **tokenize_input(char *input)
{
    
}

t_token	parse_input(char *input)
{
	t_token **tokens;
	t_ast *ast;
	int index;

    tokens = tokenize_input(input);
    
}