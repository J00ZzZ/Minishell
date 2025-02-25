#include "minishell.h" // Include your header file

static void	handle_input(char *input, char **envp)
{
	t_ast	*ast;

	ast = parse_input(input); // Parse input into AST
	if (!ast)
	{
		free(input);
		return ;
	}
	execute_ast(ast, envp); // Execute the AST
	free_ast(ast);          // Free the AST
}

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argv;
	(void)argc;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (ft_strlen(input) == 0)
		{
			free(input);
			continue ;
		}
		add_history(input);
		handle_input(input, envp);
		free(input);
	}
	write_history(".minishell_history");
	return (0);
}

/* int	main(int argc, char **argv, char **envp)
{
	(void)argv; // Unused parameters
	(void)argc;

	char *input;
	char **args;
	t_ast *ast;

	while (1)
	{
		// Display prompt and read input
		input = readline("minishell> ");
		if (!input)
			break ; // Exit on EOF (Ctrl+D)
		// Skip empty input
		if (ft_strlen(input) == 0)
		{
			free(input);
			continue ;
		}
		// Add input to history
		add_history(input);
		// Parse input into arguments
		args = parse_input(input);
		if (!args)
		{
			free(input);
			continue ; // Skip if parsing fails
		}
		// Execute the command
		if (execute_builtin(args, envp) == 0) // Try to execute as a built-in
			execute_command(args, envp);
		// Free allocated memory
		free(input);
		free(args);
	}

	// Save history and exit
	write_history(".minishell_history");
	return (0);
} */
