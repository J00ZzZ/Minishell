#include "parsing.h"

void	add_to_history(t_history **history, char *command)
{
	t_history	*new_node;
	t_history	*current;

	new_node = (t_history *)ft_calloc(1, sizeof(t_history));
	if (!new_node)
	{
		perror("ft_calloc");
		exit(EXIT_FAILURE);
	}
	new_node->command = ft_strdup(command);
	if (!new_node->command)
	{
		perror("ft_strdup");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	if (*history == NULL)
		*history = new_node;
	else
	{
		current = *history;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}