/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:52:28 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/04 15:33:54 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_string(char *c)
{
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, c, my_strlen(c));
	return (my_strlen(c));
}

int	my_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	my_putnbr(int nb)
{
	int		i;
	long	longnb;

	longnb = (long)nb;
	i = 0;
	if (longnb < 0)
	{
		i += my_putchar('-');
		longnb *= -1;
	}
	if (longnb >= 10)
	{
		i += my_putnbr(longnb / 10);
		i += my_putnbr(longnb % 10);
	}
	if (longnb >= 0 && longnb <= 9)
	{
		i += my_putchar(longnb + 48);
	}
	return (i);
}

int	my_unputnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
	{
		i += my_putnbr(nb / 10);
		i += my_putnbr(nb % 10);
	}
	else
	{
		i += my_putchar(nb + 48);
	}
	return (i);
}
