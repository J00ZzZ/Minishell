/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:24:06 by liyu-her          #+#    #+#             */
/*   Updated: 2025/04/19 16:22:53 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void perr_exit(char *str, int exit_c)
{
    ft_putstr_fd("minishell: ", STDERR_FILENO);
    ft_putstr_fd(str, STDERR_FILENO);
    perror(str);
    exit(exit_c);
}