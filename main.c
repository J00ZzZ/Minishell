/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:57:13 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/13 22:43:32 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	print_tokens(t_token *head)
{
	while (head)
	{
		printf("Char: %s, Type: %u\n", head->value, head->type);
		head = head->next;
	}
}

// void print_tokens(t_token *head)
// {
//     while (head)
//     {
//         printf("%s, %d\n", head->value, head->type);
//         if (head->next)
//             printf("\n");
//         head = head->next;
//     }
//     printf("\n");
// }

int	minishell_input(t_data *shelldata)
{
	shelldata->input = readline("minishell> ");
	if (!shelldata->input)
		return (-1);
	add_history(shelldata->input);
	if (g_sig == SIGINT || ft_strlen(shelldata->input) == 0)
	{
		if (ft_strlen(shelldata->input) == 0)
			// exit_stats(0, shelldata->var_lst);
			free(shelldata->input);
		return (0);
	}
	shelldata->token_root = ft_tokenization(shelldata->input, NULL);
	// dollar_expansion(shelldata->token_root);
	return (0);
}

void	loopterm(t_data shelldata)
{
	int	status;

	while (1)
	{
		status = minishell_input(&shelldata);
		if (status == 0)
			continue ;
		else if (status == -1)
			break ;
		// execution
	}
}

t_data	init_env(char **envp)
{
	t_data	shelldata;

	if (access("/tmp", F_OK) == -1)
		perr_exit("access /tmp", 1);
	g_sig = 0;
	ft_memset(&shelldata, 0, sizeof(t_data));
	shelldata.var_lst = copy_envp(envp);
	shelldata.last_exit_code = 0;
	term_setup();
	signal_action();
	return (shelldata);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	shelldata;

	(void)argc;
	(void)argv;
	shelldata = init_env(envp);
	loopterm(shelldata);
}

// static void	handle_input(char *input, char **envp)
// {
// 	t_ast	*ast;

// 	ast = parse_input(input); // Parse input into AST
// 	if (!ast)
// 	{
// 		free(input);
// 		return ;
// 	}
// 	execute_ast(ast, envp); // Execute the AST
// 	free_ast(ast);          // Free the AST
// }

// static void	free_cmd_list(t_cmd *cmd_list)
// {
// 	t_cmd	*current;
// 	t_cmd	*next;

// 	current = cmd_list;
// 	while (current)
// 	{
// 		next = current->next;
// 		free(current->command);
// 		ft_arrfree(current->args);
// 		free(current->input_redirect);
// 		free(current->output_redirect);
// 		free(current);
// 		current = next;
// 	}
// }

// int main(int argc, char **argv, char **envp)
// {

// }
