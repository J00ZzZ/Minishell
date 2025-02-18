#include "parsing.h"

void	free_history(t_history *history)
{
	t_history	*tmp;

	while (history)
	{
		tmp = history;
		history = history->next;
		free(tmp->command);
		free(tmp);
	}
}