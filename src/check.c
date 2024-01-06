/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:41:20 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/06 16:43:38 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->bytes[0 * map->width + i] != '1')
			map_quit(map, "top border is not a wall on the map");
		if (map->bytes[(map->height - 1) * map->width + i] != '1')
			map_quit(map, "bottom border is not a wall on the map");
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->bytes[i * map->width + 0] != '1')
			map_quit(map, "left is not a wall on the map");
		if (map->bytes[i * map->width + (map->width - 1)] != '1')
			map_quit(map, "right is not a wall on the map");
		i++;
	}
}

void	check_pec(t_map *map)
{
	int	i;
	int	player_count;
	int	exit_count;

	i = 0;
	player_count = 0;
	exit_count = 0;
	while (i < map->width * map->height)
	{
		if (map->bytes[i] != 'P' && map->bytes[i] != 'C'
			&& map->bytes[i] != 'E' && map->bytes[i] != '1'
			&& map->bytes[i] != '0')
			map_quit(map, "invalid items on the map");
		if (map->bytes[i] == 'P')
			player_count++;
		if (map->bytes[i] == 'E')
			exit_count++;
		if (map->bytes[i] == 'C')
			map->coin_count++;
		i++;
	}
	if (player_count != 1)
		map_quit(map, "Too much or no player on the map");
	if (exit_count != 1)
		map_quit(map, "Too much or no exit on the map");
}

void	flood_fill(t_map *map, char *copy, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (copy[y * map->width + x] != '0'
		&& copy[y * map->width + x] != 'C'
		&& copy[y * map->width + x] != 'E')
		return ;
	copy[y * map->width + x] = '*';
	flood_fill(map, copy, x, y - 1);
	flood_fill(map, copy, x, y + 1);
	flood_fill(map, copy, x - 1, y);
	flood_fill(map, copy, x + 1, y);
}

void	check_path(t_map *map)
{
	char	*copy;
	int		exit_filled;

	copy = malloc(map->width * map->height);
	if (copy == NULL)
		map_quit(map, "Can't allocate map copy");
	ft_memcpy(copy, map->bytes, map->width * map->height);
	flood_fill(map, copy, map->player_x, map->player_y);
	exit_filled = copy[map->exit_y * map->width + map->exit_x] == '*';
	free(copy);
	if (!exit_filled)
		map_quit(map, "No exit possible on the map");
}
