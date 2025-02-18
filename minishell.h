/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 04:41:56 by liyu-her          #+#    #+#             */
/*   Updated: 2025/02/19 04:42:06 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h" // Include the libft header
# include <sys/wait.h>
# include <unistd.h>

# define MAX_INPUT_SIZE 1024
# define READ_BUFFER_SIZE 1024

// Structure for the linked list node
typedef struct s_history
{
	char				*command;
	struct s_history	*next;
}						t_history;

// Function prototypes
void					add_to_history(t_history **history, char *command);
void					print_history(t_history *history);
void					free_history(t_history *history);
void					execute_command(char *command);
char	*read_input(void); // Custom function to read input

#endif