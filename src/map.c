/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:20:10 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/06 16:40:01 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * La fonction `get_width` calcule la largeur de la carte. Elle lit les
 * caractères du fichier jusqu'à rencontrer un '\n'. Pour chaque caractère
 * qui n'est pas un '\n', elle incrémente `width` dans `map`. En cas d'erreur
 * de lecture, elle appelle `map_quit` avec le message d'erreur correspondant.
 */
void	get_width(t_map *map, int fd)
{
	int		read_count;
	char	buffer;

	while (1)
	{
		read_count = read(fd, &buffer, 1);
		if (read_count < 0)
			map_quit(map, strerror(errno));
		if (buffer == '\n')
			break ;
		map->width++;
	}
}

/*
 * La fonction `get_height` calcule la hauteur de la carte. Elle lit les
 * caractères du fichier jusqu'à rencontrer un EOF (fin de fichier). Pour
 * chaque '\n' rencontré, elle incrémente `height` dans `map`. En cas d'erreur
 * de lecture, elle appelle `map_quit` avec le message d'erreur correspondant.
 */
void	get_height(t_map *map, int fd, int file_size)
{
	int		read_count;
	char	buffer;

	while (1)
	{
		read_count = read(fd, &buffer, 1);
		if (read_count < 0)
			map_quit(map, strerror(errno));
		if (read_count == 0)
			break ;
		file_size++;
	}
	if (file_size % (map->width + 1) == map->width)
		file_size++;
	if (file_size % (map->width + 1) != 0)
		map_quit(map, "map not rectangularisalisation please");
	map->height = file_size / (map->width + 1);
}

/*
 * La fonction `get_size` calcule la largeur et la hauteur de la carte.
 * Elle ouvre le fichier en lecture seule, puis appelle `get_width` et
 * `get_height` pour déterminer les dimensions de la carte. En cas d'erreur
 * lors de l'ouverture du fichier, elle appelle `map_quit` avec le message
 * d'erreur correspondant.
 */
void	get_size(t_map *map, char *filename)
{
	int		fd;

	map->width = 0;
	map->height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		map_quit(map, strerror(errno));
	get_width(map, fd);
	get_height(map, fd, map->width + 1);
	close(fd);
}

/*
 * La fonction `read_map` lit le contenu de la carte à partir du fichier.
 * Elle ouvre le fichier en lecture seule, puis lit chaque ligne de la carte
 * dans le tampon `bytes` de la structure `map`. Si la lecture d'une ligne
 * échoue ou si la lecture du caractère de nouvelle ligne échoue, elle appelle
 * `map_quit` avec le message d'erreur correspondant.
 */
void	read_map(t_map *map, char *filename)
{
	int		y;
	int		fd;
	char	new_line;
	char	*buffer;

	buffer = map->bytes;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		map_quit(map, strerror(errno));
	y = 0;
	while (y < map->height)
	{
		if (read(fd, buffer, map->width) != map->width)
			map_quit(map, strerror(errno));
		if (read(fd, &new_line, 1) < 0)
			map_quit(map, strerror(errno));
		buffer += map->width;
		y++;
	}
	close(fd);
}

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

t_map	*load_map(char *filename)
{
	t_map	*map;
	char	*p_e_position;

	map = ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		return (NULL);
	get_size(map, filename);
	map->bytes = ft_calloc(map->width, map->height);
	if (map->bytes == NULL)
		map_quit(map, "load_map bytes allocated error");
	read_map(map, filename);
	check_borders(map);
	check_pec(map);
	if (map->coin_count < 1)
		map_quit(map, "No keys on the map");
	p_e_position = ft_memchr(map->bytes, 'P', map->width * map->height);
	*p_e_position = '0';
	map->player_y = (p_e_position - map->bytes) / map->width;
	map->player_x = (p_e_position - map->bytes) % map->width;
	p_e_position = ft_memchr(map->bytes, 'E', map->width * map->height);
	map->exit_y = (p_e_position - map->bytes) / map->width;
	map->exit_x = (p_e_position - map->bytes) % map->width;
	check_path(map);
	return (map);
}
