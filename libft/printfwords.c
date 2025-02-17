/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:28:47 by hang              #+#    #+#             */
/*   Updated: 2024/07/24 13:45:08 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printfputchar(int c, int *length)
{
	write(1, &c, 1);
	(*length)++;
}

void	printfstring(char *str, int *length)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (str[i])
		printfputchar(str[i++], length);
}
