#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_cmd
{
	char *command;         // The command to execute
	char **args;           // Array of arguments (NULL-terminated)
	char *input_redirect;  // File for input redirection (NULL if none)
	char *output_redirect; // File for output redirection (NULL if none)
	int is_background;     // 1 for background execution, 0 otherwise
	int is_pipe;           // 1 if the command is followed by a pipe, 0 otherwise
	struct s_cmd *next;    // Next command in the pipeline (NULL if none)
}	t_cmd;

# include "builtin/builtin.h"
# include "execution/execution.h"
# include "libft/libft.h"
# include "parsing/parsing.h"
# include <readline/history.h>
# include <readline/readline.h>

#endif