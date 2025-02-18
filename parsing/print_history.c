#include "parsing.h"

void	print_history(t_history *history)
{
	t_history	*current;
	int			index;

	current = history;
	index = 1;
	while (current)
	{
		ft_printf("%d: %s\n", index, current->command);
		current = current->next;
		index++;
	}
}