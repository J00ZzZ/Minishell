/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:14 by liyu-her          #+#    #+#             */
/*   Updated: 2024/06/04 15:34:05 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_args(va_list args, const char format)
{
	if (format == 'c')
		return (my_putchar(va_arg(args, int)));
	else if (format == '%')
		return (my_putchar('%'));
	else if (format == 's')
		return (my_string(va_arg(args, char *)));
	else if (format == 'i' || format == 'd')
		return (my_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (my_unputnbr(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (my_hexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (my_pointer(va_arg(args, void *)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_args(args, format[i + 1]);
			i++;
		}
		else
			len += my_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	unsigned long i;

// 	i = 42949672434;
// 	printf("%p\n", &i);
// 	ft_printf("%p\n", &i);
// }
