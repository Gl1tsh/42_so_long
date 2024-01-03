/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:20:10 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/03 19:46:19 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_size(t_map *map, char *filename)
{
	int		fd;
	int		read_count;
	int		file_size;
	char	buffer;

	map->width = 0;
	map->height = 0;

	fd = open(filename, O_RDONLY);
	// check fd < 0

	// Cherche le premier \n ce qui determine la largeur de la map	
	while (1)
	{
		read_count = read(fd, &buffer, 1);
		// check read_count == 0
		// check read_count == -1
		if (buffer == '\n')
			break;
		map->width++;
	}
	file_size = map->width + 1;

	// Compte le nombre total de bytes (caracteres) du fichier
	while (1)
	{
		read_count = read(fd, &buffer, 1);
		// check read_count == 1
		if (read_count == 0)
			break;
		file_size++;
	}

	// +1 pour ajouter le baque,slache,haine car il n'est pas dans la memoire
	map->height = file_size / (map->width + 1);
}


t_map *load_map(char *filename)
{
	t_map *map = malloc(sizeof(t_map));

	get_size(map, filename);

	return map;
}

