
#include "execution.h"

// Helper function to create a new command node
t_cmd	*create_cmd_node(char *command, char **args, char *input_redirect,
		char *output_redirect, int is_background)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->command = ft_strdup(command);
	node->args = args;
	node->input_redirect = input_redirect ? ft_strdup(input_redirect) : NULL;
	node->output_redirect = output_redirect ? ft_strdup(output_redirect) : NULL;
	node->is_background = is_background;
	node->next = NULL;
	return (node);
}

// Helper function to free a command node
void	free_cmd_node(t_cmd *node)
{
	if (!node)
		return ;
	free(node->command);
	ft_arrfree(node->args); // Assuming ft_arrfree frees an array of strings
	free(node->input_redirect);
	free(node->output_redirect);
	free(node);
}

// Main parsing function
t_cmd	*parse_input(char *input)
{
	t_cmd	*cmd_list;
	t_cmd	*current_cmd;
	char	*token;
	char	*saveptr;
	char	*command;
	char	**args;
	char	*input_redirect;
	char	*output_redirect;
	int		is_background;
	int		i;
	t_cmd	*temp;

	cmd_list = NULL;
	current_cmd = NULL;
	command = NULL;
	args = NULL;
	input_redirect = NULL;
	output_redirect = NULL;
	is_background = 0;
	i = 0;
	// Tokenize the input string
	token = ft_strtok_r(input, " ", &saveptr);
	while (token)
	{
		// Handle redirections
		if (ft_strncmp(token, "<", 1) == 0)
		{
			token = ft_strtok_r(NULL, " ", &saveptr);
			if (token)
				input_redirect = token;
		}
		else if (ft_strncmp(token, ">", 1) == 0 || ft_strncmp(token, ">>", 2) == 0)
		{
			output_redirect = token;
			token = ft_strtok_r(NULL, " ", &saveptr);
			if (token)
				output_redirect = token;
		}
		// Handle background execution
		else if (ft_strncmp(token, "&", 1) == 0)
		{
			is_background = 1;
		}
		// Handle commands and arguments
		else
		{
			if (!command)
				command = token; // First token is the command
			args = realloc(args, (i + 1) * sizeof(char *));
			args[i] = ft_strdup(token);
			i++;
		}
		token = ft_strtok_r(NULL, " ", &saveptr);
	}
	// Null-terminate the args array
	if (args)
	{
		args = realloc(args, (i + 1) * sizeof(char *));
		args[i] = NULL;
	}
	// Create a command node and add it to the linked list
	if (command)
	{
		current_cmd = create_cmd_node(command, args, input_redirect,
				output_redirect, is_background);
		if (!cmd_list)
			cmd_list = current_cmd;
		else
		{
			temp = cmd_list;
			while (temp->next)
				temp = temp->next;
			temp->next = current_cmd;
		}
	}
	return (cmd_list);
}
