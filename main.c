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
		ft_printf("minishell> ");
		input = read_input();
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
			add_to_history(&history, input);
			execute_command(input, envp);
		}
		free(input);
	}
	free_history(history);
	return (0);
}