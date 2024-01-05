/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:15:20 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 18:15:23 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr_s;
	unsigned char	chr;

	ptr_s = (unsigned char *)s;
	chr = (unsigned char)c;
	while (n)
	{
		if (*ptr_s == chr)
			return (ptr_s);
		n--;
		ptr_s++;
	}
	return (0);
}