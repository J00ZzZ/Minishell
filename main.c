#include "minishell.h" // Include your header file

int	main(int argc, char **argv, char **envp)
{
	(void)argv; // Unused parameters
	(void)argc;

	char *input;
	char **args;

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
}
 