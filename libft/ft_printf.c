/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:54:13 by nagiorgi          #+#    #+#             */
/*   Updated: 2023/12/30 18:52:48 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_10(va_arg(args, int)));
	else if (format == 'p')
	{
		ft_putstr("0x");
		return (ft_putnbr_16(va_arg(args, unsigned long), 0) + 2);
	}
	else if (format == 'u')
		return (ft_putnbr_10_u(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_16(va_arg(args, unsigned int), format == 'X'));
	else if (format == '%')
		return (ft_putchar(format));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count_char;

	count_char = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count_char += ft_print_format(*str, args);
		}
		else
			count_char += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (count_char);
}
