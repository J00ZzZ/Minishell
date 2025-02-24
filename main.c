#include "minishell.h"

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
		else if (ft_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break ;
		}
		else if (ft_strlen(input) > 0)
		{
			add_history(input);
			execute_command(input, envp);
		}
		free(input);
	}
	write_history(".minishell_history");
	return (0);
}
