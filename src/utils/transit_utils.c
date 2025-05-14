#include "../../inc/minishell.h"

void	handle_redirection(t_token **tokens, t_cmd *cmd)
{
	if ((*tokens)->type == TOKEN_IN_REDIR || (*tokens)->type == TOKEN_HEREDOC)
	{
		if ((*tokens)->next && (*tokens)->next->type == TOKEN_WORD)
		{
			cmd->input_redirect = ft_strdup((*tokens)->next->value);
			*tokens = (*tokens)->next->next;
		}
		else
			perr_exit("Error: Missing filename after redirection\n", 1);
	}
	else if ((*tokens)->type == TOKEN_OUT_REDIR
		|| (*tokens)->type == TOKEN_APPEND)
	{
		if ((*tokens)->next && (*tokens)->next->type == TOKEN_WORD)
		{
			cmd->output_redirect = ft_strdup((*tokens)->next->value);
			*tokens = (*tokens)->next->next;
		}
		else
			perr_exit("Error: Missing filename after redirection\n", 1);
	}
}

int	is_redirection_token(t_token_type type)
{
	return (type == TOKEN_IN_REDIR || type == TOKEN_OUT_REDIR
		|| type == TOKEN_APPEND || type == TOKEN_HEREDOC);
}

int	count_args(char **args)
{
	int	count = 0;
	while (args && args[count])
		count++;
	return (count);
}


char	**add_arg_to_array(char **args, char *new_arg)
{
	int		i = 0;
	int		size = count_args(args);
	char	**new_args = malloc(sizeof(char *) * (size + 2));

	if (!new_args)
		return (NULL);
	while (i < size)
	{
		new_args[i] = args[i];
		i++;
	}
	new_args[i++] = strdup(new_arg);
	new_args[i] = NULL;
	free(args);
	return (new_args);
}

void	ft_cmd(t_token **token, t_cmd *cmd)
{
	while (*token && (*token)->type == TOKEN_WORD)
	{
		if (!cmd->command)
			cmd->command = strdup((*token)->value);
		cmd->args = add_arg_to_array(cmd->args, (*token)->value);
		*token = (*token)->next;
	}
}
