#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "builtin.h"
# include "execution.h"
# include "parsing.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <unistd.h>

# define C_META " '\"|<>$"
# define C_QUOTE "\"'$"
# define C_BAN "\\;&()*"

extern int	g_sig;

typedef struct s_cmd
{
	char *command;         // The command to execute done
	char **args;           // Array of arguments (NULL-terminated)
	char *input_redirect;  // File for input redirection (NULL if none) done
	char *output_redirect; // File for output redirection (NULL if none) done
	int is_pipe;           // done
	struct s_cmd *next;    // Next command in the pipeline (NULL if none)
}			t_cmd;

typedef struct s_data
{
	t_token	*token_root;
	t_cmd	*cmd_root;
	char	**var_lst;
	char	*input;
	int		last_exit_code;
}			t_data;

void		perr_exit(char *str, int exit_c);
void		loopterm(t_data shelldata);
t_data		init_env(char **envp);
int			ft_envp_len(char **envp);
int			ft_strcmp(const char *s1, const char *s2);

// parse to execution
t_cmd		*ft_transit(t_token *token, t_cmd *head, t_cmd *cmd);
void		ft_cmd(t_token **token, t_cmd *cmd);
char		**add_arg_to_array(char **args, char *new_arg);
int			count_args(char **args);

// test
void		print_cmd_list(t_cmd *cmd_list);
#endif

// typedef struct s_node
// {
// 	char *value;
// 	int num;
// } t_node;

// typedef struct s_data
// {
// 	t_node *node_root;
// 	t_token	*token_root;
// } t_data;
// typedef struct s_cmd
// {
// 	char *command;         // The command to execute
// 	char **args;           // Array of arguments (NULL-terminated)
// 	char *input_redirect;  // File for input redirection (NULL if none)
// 	char *output_redirect; // File for output redirection (NULL if none)
// 	int is_background;     // 1 for background execution, 0 otherwise
// 	struct s_cmd *next;    // Next command in the pipeline (NULL if none)
// }			t_cmd;

// # include "builtin.h"
// # include "execution.h"
// # include "../libft/libft.h"
// # include "parsing.h"
// # include <readline/history.h>
// # include <readline/readline.h>
// # include <signal.h>
// # include <termios.h>

// #define C_META " '\"|<>$"
// #define C_QUOTE "\"'$"
// #define C_BAN "\\;&|()*"

// void perr_exit(char *str, int exit_c);

// #endif