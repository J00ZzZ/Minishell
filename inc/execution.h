/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:00:55 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/13 22:11:03 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../libft/libft.h"
# include "minishell.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/fcntl.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd t_cmd;

void	execute_external_command(t_cmd *cmd, char **envp);
t_cmd	*parse_input(char *input);
int		is_builtin(t_cmd *cmd);
char	**execute_builtin(t_cmd *cmd, char **envp);

#endif