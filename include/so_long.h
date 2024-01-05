/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:19:33 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 16:34:23 by nagiorgi         ###   ########.fr       */
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

# define SUCCESS 0
# define FAILURE 1

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

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
	void		*mlx;
	void		*win;
	t_map		*map;
	void		*background_img;
	void		*wall_img;
	void		*key_img;
	void		*exit_img;
	void		*hero_img;
	void		*zombie_img;
	long long	last_tick;
}			t_game;

/* Fonctions check erreur */
int		ft_free(t_game *game);
int		ft_free_error(t_game *game, const char *error_msg);
t_map	*load_map(char *filename);

#endif
