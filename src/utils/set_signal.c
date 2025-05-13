/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 02:45:10 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/13 03:44:09 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void exit_stats(int exit_code, t_var *var_lst)
{
    char *s;
    char *code;
    t_var *exit_stats;

    exit_stats = var_node("?", var_lst);
}

// void set_signal_exit(t_data *shelldata)
// {
//     if (g_sig == SIGINT)
//         set_exit(130, shelldata->var_lst);
// }