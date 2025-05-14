/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 22:12:41 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/15 01:27:49 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	perr_exit(char *str, int exit_c)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	perror(str);
	exit(exit_c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->command = NULL;
	cmd->args = NULL;
	cmd->input_redirect = NULL;
	cmd->output_redirect = NULL;
	cmd->is_pipe = 0;
	cmd->next = NULL;
	return (cmd);
}

// t_cmd	*parse_tokens_to_cmds(t_token *tokens)
// {
// 	t_cmd	*cmd_head;
// 	t_cmd	*current_cmd;

// 	cmd_head = NULL;
// 	current_cmd = NULL;
// 	while (tokens)
// 	{
// 		t_cmd *new_cmd = init_cmd();
// 		fill_command_and_args(&tokens, new_cmd);
// 		while (tokens && is_redirection_token(tokens->type))
// 		{
// 			handle_redirection(&tokens, new_cmd);
// 		}
// 		if (tokens && tokens->type == TOKEN_PIPE)
// 		{
// 			new_cmd->is_pipe = 1;
// 			tokens = tokens->next;
// 		}
// 		if (!cmd_head)
// 			cmd_head = new_cmd;
// 		else
// 			current_cmd->next = new_cmd;
// 		current_cmd = new_cmd;
// 	}
// 	return (cmd_head);
// }

t_cmd	*ft_transit(t_token *token, t_cmd *head, t_cmd *cmd)
{
	t_cmd	*new;

	while (token)
	{
		new = init_cmd();
		if (!new)
			return (NULL);
		ft_cmd(&token, new);
		while (token && is_redirection_token(token->type))
			handle_redirection(&token, new);
		if (token && token->type == TOKEN_PIPE)
		{
			new->is_pipe = 1;
			token = token->next;
		}
		if (!head)
			head = new;
		else
			cmd->next = new;
		cmd = new;
	}
	return (head);
}

// t_token	*token;
// t_cmd	*cmd;

// token = shelldata->token_root;
// cmd = init_cmd();
// while (token)
// {
// 	//function for command and function for args
// 	ft_argm();
// 	if (token && shelldata->token_root && token == shelldata->token_root
// 		&& token->value == TOKEN_WORD)
// 		cmd->command = token->value;
// 	while (token && is_redirection_token(token->type))
// 		handle_redirection(&token, cmd);
// 	if (token && token->type == TOKEN_PIPE)
// 	{
// 		cmd->is_pipe = 1;
// 		token = token->next;
// 	}
// }

// while (token)
// {
// 	printf("final: %s, type: %d, openend: %d\n", token->value, token->type,
// 		token->openend);
// 	token = token->next;
// }