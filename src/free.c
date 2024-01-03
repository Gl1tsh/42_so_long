/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:13 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/03 19:04:03 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	map->map = NULL;
	i = 0;
	while (map->map_copy[i])
		free(map->map_copy[i++]);
	free(map->map_copy);
	map->map_copy = NULL;
	return (SUCCESS);
}

int	ft_free_error(t_map *map, const char *error_msg)
{
	ft_free(map);
	ft_printf("Error: ");
	ft_printf("%s \n", error_msg);
	return (FAILURE);
}
