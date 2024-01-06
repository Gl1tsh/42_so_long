/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:19:33 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/06 16:42:34 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Librairies */
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>

# define SUCCESS 0
# define FAILURE 1

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_map
{
	char	*bytes;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		coin_count;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*background_img;
	void	*wall_img;
	void	*key_img;
	void	*exit_img;
	void	*hero_img;
	int		move_count;
}			t_game;

void	game_quit(t_game *game);
void	game_quit_error(t_game *game, const char *error_msg);
t_map	*load_map(char *filename);

void	my_put_image_at(t_game *game, void *image, int x, int y);
void	*my_load_image(t_game *game, char *filename);
int		my_coord(t_game *game, int x, int y);

void	map_quit(t_map *map, const char *error_msg);
void	check_borders(t_map *map);
void	check_pec(t_map *map);
void	check_path(t_map *map);

#endif
