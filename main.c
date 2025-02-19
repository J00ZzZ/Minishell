#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;

	char		*input;
	t_history	*history;

	history = NULL;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (ft_strncmp(input, "history", 7) == 0)
			print_history(history);
		else if (ft_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break ;
		}
		else if (ft_strlen(input) > 0)
		{
			add_history(input);
			add_to_history(&history, input);
			execute_command(input, envp);
		}
		free(input);
	}
	write_history(".minishell_history");
	free_history(history);
	return (0);
}
