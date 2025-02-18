#ifndef PARSING_H
# define PARSING_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define READ_BUFFER_SIZE 1024

typedef struct s_history
{
	char				*command;
	struct s_history	*next;
}	t_history;

char		*read_input(void);
void		add_to_history(t_history **history, char *command);
void		print_history(t_history *history);
void		free_history(t_history *history);

#endif