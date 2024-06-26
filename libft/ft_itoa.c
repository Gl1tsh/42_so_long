/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:52:28 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/06 13:52:33 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_intlen(int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		len += 1;
	while (number != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	unsigned int	number;
	unsigned int	size;

	size = ft_intlen(n);
	result = (char *)malloc(sizeof(char) * (size) + 1);
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		result[0] = '0';
	result[size] = '\0';
	while (number != 0)
	{
		result[size - 1] = (number % 10) + '0';
		number = number / 10;
		size--;
	}
	return (result);
}
