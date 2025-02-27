#include "minishell.h" // Include your header file

int	main(int argc, char **argv, char **envp)
{
	(void)argv; // Unused parameters
	(void)argc;

	char	*input;
	char	**args;
	char	**envp_copy;

	// Create a copy of envp to allow modifications
	envp_copy = ft_arrdup(envp); // Assume ft_arrdup is implemented in libft
	if (!envp_copy)
		return (1); // Exit if memory allocation fails

	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ; // Exit on EOF (Ctrl+D)
		if (ft_strlen(input) == 0) // Use ft_strlen from libft
		{
			free(input);
			continue ;
		}
		add_history(input); // Add input to history
		args = parse_input(input); // Parse input into arguments
		if (!args)
		{
			free(input);
			continue ; // Skip if parsing fails
		}
		// Execute the command
		envp_copy = execute_builtin(args, envp_copy); // Update envp_copy
		if (envp_copy == NULL)
		{
			ft_putstr_fd("minishell: memory allocation failed\n", 2);
			free(input);
			free(args);
			break ; // Exit if memory allocation fails
		}
		if (is_builtin(args) == 0) // If not a built-in, execute as external command
			execute_command(args, envp_copy);
		// Free allocated memory
		free(input);
		free(args);
	}

	// Save history and exit
	write_history(".minishell_history");
	ft_arrfree(envp_copy); // Free the environment copy
	return (0);
}
