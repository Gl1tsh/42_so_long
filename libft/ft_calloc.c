/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 20:34:59 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 20:35:03 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	full_size;
	void	*ptr;

	full_size = count * size;
	ptr = malloc(full_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, full_size);
	return (ptr);
}
