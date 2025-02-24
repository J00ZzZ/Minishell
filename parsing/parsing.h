/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 07:01:48 by liyu-her          #+#    #+#             */
/*   Updated: 2025/02/24 07:44:04 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define READ_BUFFER_SIZE 1024

typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIRECT,
	NODE_LOGICAL,
	NODE_SEQUENCE,
}			t_node_type;

typedef struct s_ast
{
	t_node_type type;
	struct  t_ast *left;
	struct t_ast *right;
	char **args;
	char *infile;
	char *outfile;
	int append;
	int background;
}			t_ast;

#endif