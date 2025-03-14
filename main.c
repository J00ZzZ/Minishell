#include "minishell.h" // Include your header file

static void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*current;

	
	t_cmd	*current;
	t_cmd	*next;

	current = cmd_list;
	while (current)
	{
		next = current->next;
		free(current->command);
		ft_arrfree(current->args);
		free(current->input_redirect);
		free(current->output_redirect);
		free(current);
		current = next;
	}
}

#include "minishell.h" // Include your header file

int main(int argc, char **argv, char **envp)
{
    (void)argv; // Unused parameters
    (void)argc;

    char *input;
    t_cmd *cmd_list; // Linked list of commands
    char **envp_copy;

    // Create a copy of envp to allow modifications
    envp_copy = ft_arrdup(envp); // Assume ft_arrdup is implemented in libft
    if (!envp_copy)
        return (1); // Exit if memory allocation fails

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

        // Parse input into a linked list of commands
        cmd_list = parse_input(input);
        if (!cmd_list)
        {
            free(input);
            continue ; // Skip if parsing fails
        }

        // Execute the command(s) in the linked list
        t_cmd *current = cmd_list;
        while (current)
        {
            if (is_builtin(current)) // Check if the command is a built-in
            {
                envp_copy = execute_builtin(current, envp_copy); // Execute built-in
                if (envp_copy == NULL)
                {
                    ft_putstr_fd("minishell: memory allocation failed\n", 2);
                    free(input);
                    free_cmd_list(cmd_list); // Free the linked list
                    ft_arrfree(envp_copy);    // Free the environment copy
                    return (1);               // Exit if memory allocation fails
                }
            }
            else
            {
                // If not a built-in, execute as external command
                execute_external_command(current, envp_copy);
            }
            current = current->next; // Move to the next command in the pipeline
        }

        // Free allocated memory
        free(input);
        free_cmd_list(cmd_list); // Free the linked list
    }

    // Save history and exit
    rl_clear_history();    // Clear readline history
    ft_arrfree(envp_copy); // Free the environment copy
    return (0);
}
