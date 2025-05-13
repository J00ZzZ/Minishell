/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:54:35 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/12 23:58:58 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_heredoc(t_token *token)
{
	if (!token || !token->prev || token->type != TOKEN_WORD)
		return (0);
	token = token->prev;
	while (token && token->type == TOKEN_SPACE)
		token = token->prev;
	if (token && token->type == TOKEN_HEREDOC)
		return (1);
	return (0);
}

char	*ft_limiter(char *token_root)
{
	char	*trimmed;

	if (token_root[0] == '\'' || token_root[0] == '\"')
	{
		trimmed = ft_substr(token_root, 1, ft_strlen(token_root) - 2);
		if (!trimmed)
			perr_exit("malloc failed", EXIT_FAILURE);
		return (trimmed);
	}
	trimmed = ft_substr(token_root, 0, ft_strlen(token_root));
	if (!trimmed)
		perr_exit("malloc failed", EXIT_FAILURE);
	return (trimmed);
}

int	make_heredoc_fd(t_token *token, int heredoc_id)
{
	char	*heredoc_file;
	char	*buffer;
	int		fd;

	buffer = ft_itoa(heredoc_id);
	if (!buffer)
		perr_exit("malloc failed", EXIT_FAILURE);
	heredoc_file = ft_strjoin("/tmp/heredoc_", buffer);
	free(buffer);
	if (!heredoc_file)
		perr_exit("malloc failed", EXIT_FAILURE);
	fd = open(heredoc_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
	{
		free(heredoc_file);
		return (0);
	}
	token->fhere_doc = heredoc_file;
	return (fd);
}

int	input_heredoc(t_token *token, int heredoc_id)
{
	char	*input;
	int		fd;
	char	*limiter;
	int		limiter_len;

	fd = make_heredoc_fd(token, heredoc_id);
	if (!fd)
		return (0);
	limiter = ft_limiter(token->value);
	limiter_len = ft_strlen(limiter);
	while (1)
	{
		input = readline("> ");
		if (!input || (ft_strcmp(input, limiter) == 0
				&& limiter_len == ft_strlen(input)) || g_sig == SIGINT)
			break ;
		ft_putendl_fd(input, fd);
		free(input);
	}
	free(input);
	free(limiter);
	close(fd);
	if (g_sig == SIGINT)
		return (0);
	return (1);
}
