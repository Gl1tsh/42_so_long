/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:18:40 by nagiorgi          #+#    #+#             */
/*   Updated: 2023/12/30 18:52:52 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_10(long nb)
{
	int	count_char;

	count_char = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		count_char++;
		nb = -nb;
	}
	return (count_char + ft_putnbr_10_u(nb));
}

int	ft_putnbr_10_u(unsigned long nb)
{
	int	count_char;

	count_char = 0;
	if (nb >= 10)
	{
		count_char = count_char + ft_putnbr_10(nb / 10);
		nb %= 10;
	}
	ft_putchar(nb + '0');
	count_char++;
	return (count_char);
}

int	ft_putnbr_16(unsigned long nb, int uppercase)
{
	char	*hexadecimal;
	int		count_char;

	count_char = 0;
	if (uppercase)
		hexadecimal = "0123456789ABCDEF";
	else
		hexadecimal = "0123456789abcdef";
	if (nb >= 16)
	{
		count_char = count_char + ft_putnbr_16(nb / 16, uppercase);
		nb %= 16;
	}
	ft_putchar(hexadecimal[nb]);
	count_char++;
	return (count_char);
}
