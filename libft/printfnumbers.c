/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:28:43 by hang              #+#    #+#             */
/*   Updated: 2024/07/24 13:45:05 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printfinteger(long numbers, int *length)
{
	if (numbers == INT_MIN)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (numbers < 0)
	{
		printfputchar('-', length);
		numbers *= -1;
	}
	if (numbers >= 10)
	{
		printfinteger((numbers / 10), length);
		printfinteger((numbers % 10), length);
	}
	else
		printfputchar((numbers + 48), length);
}

void	printfpointer(uintptr_t ptr, int *length)
{
	write(1, "0x", 2);
	(*length) += 2;
	printfhexadecimal(ptr, length, 'x');
}

void	printfhexadecimal(unsigned long nb, int *length, char xorX)
{
	char	buffer[16];
	char	*base;
	int		i;

	i = 0;
	if (xorX == 'x')
		base = "0123456789abcdef";
	else if (xorX == 'X')
		base = "0123456789ABCDEF";
	if (nb == 0)
	{
		printfputchar('0', length);
		return ;
	}
	while (nb > 0)
	{
		buffer[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	while (buffer[--i])
		printfputchar(buffer[i], length);
}
