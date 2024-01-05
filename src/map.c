/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:20:10 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 20:42:12 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_width(t_map *map, int fd)
{
	int		read_count;
	char	buffer;

	while (1)
	{
		read_count = read(fd, &buffer, 1);
		if (buffer == '\n')
			break ;
		map->width++;
	}
}

void	get_height(t_map *map, int fd, int file_size)
{
	int		read_count;
	char	buffer;

	while (1)
	{
		read_count = read(fd, &buffer, 1);
		if (read_count == 0)
			break ;
		file_size++;
	}
	map->height = file_size / (map->width + 1);
}

void	get_size(t_map *map, char *filename)
{
	int		fd;

	map->width = 0;
	map->height = 0;
	fd = open(filename, O_RDONLY);
	get_width(map, fd);
	get_height(map, fd, map->width + 1);
	close(fd);
}

void	read_map(t_map *map, char *filename)
{
	int		y;
	int		fd;
	char	new_line;
	char	*buffer;

	buffer = map->bytes;
	fd = open(filename, O_RDONLY);
	y = 0;
	while (y < map->height)
	{
		read(fd, buffer, map->width);
		read(fd, &new_line, 1);
		buffer += map->width;
		y++;
	}
	close(fd);
}

t_map	*load_map(char *filename)
{
	int		i;
	t_map	*map;
	char	*player_position;

	map = ft_calloc(sizeof(t_map), 1);
	get_size(map, filename);
	map->bytes = ft_calloc(map->width, map->height);
	read_map(map, filename);
	i = 0;
	map->coin_count = 0;
	while (i < map->width * map->height)
	{
		if (map->bytes[i] == 'C')
			map->coin_count++;
		i++;
	}
	player_position = ft_memchr(map->bytes, 'P', map->width * map->height);
	if (player_position == NULL)
		exit(3);
	*player_position = '0';
	map->player_y = (player_position - map->bytes) / map->width;
	map->player_x = (player_position - map->bytes) % map->width;
	return (map);
}
