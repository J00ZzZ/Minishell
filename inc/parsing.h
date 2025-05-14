/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:56:19 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/14 19:17:53 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_IN_REDIR,
	TOKEN_OUT_REDIR,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_SPACE
}						t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	int					openend;
	char				*fhere_doc;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_var
{
	char				*str;
	struct s_var		*next;
}						t_var;

void					term_setup(void);
char					**copy_envp(char **envp);
void					signal_action(void);
void					handle_signal(int signal);

// tokenization
t_token					*ft_tokenization(char *input, t_token *token_root);
t_token					*inputoken(char *input);
t_token					*input_to_token(char *start, int len);
t_token					*ft_new_token(char *value);
void					ft_tokenadd_back(t_token **token_ptr, t_token *new);
void					ft_tokentype(t_token *token);
void					tk_comb_next(t_token *token);
void					token_remove(t_token *token);
void					ft_rmvspace(t_token *token);
void					ft_openend(t_token *token);
void					ft_quotes(t_token *token);
void					ft_double(t_token *token);
void					ft_word(t_token *token);
void					clean_token(t_token *token_root);
void					ft_freetoken(t_token *token_root);
int						ft_valid(t_token *token);
void					ft_combspce(t_token *token);

// ischar
int						is_ban_char(char input);
int						is_quote(char input);
int						is_meta(char input);

// heredoc
int						is_heredoc(t_token *token);
char					*ft_limiter(char *token_root);
int						make_heredoc_fd(t_token *token, int heredoc_id);
int						input_heredoc(t_token *token, int heredoc_id);

// redirect
void					handle_redirection(t_token **tokens, t_cmd *cmd);
int						is_redirection_token(t_token_type type);
#endif