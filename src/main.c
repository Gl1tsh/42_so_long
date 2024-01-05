/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:22:50 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 17:50:42 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

#define KEY_W 119
#define KEY_S 115
#define KEY_A 97
#define KEY_D 100

int quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return 0;
}

void	move_player(t_game *game)
{
	game->map->coin_count++;
}

void	draw_player(t_game *game)
{
	game->map->coin_count++;
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->bytes[y * game->map->width + x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 32, y * 32);
			else if (game->map->bytes[y * game->map->width + x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->background_img, x * 32, y * 32);
			else if (game->map->bytes[y * game->map->width + x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->key_img, x * 32, y * 32);
			else if (game->map->bytes[y * game->map->width + x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->hero_img, x * 32, y * 32);
			else if (game->map->bytes[y * game->map->width + x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

//#include <stdio.h>
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return 1;

	game.map = load_map(argv[1]);
	if (game.map == NULL)
		return (ft_free_error(&game, "erreur de map"));
	ft_printf("load map : ok\n");

	//initialiser la mz lib
    game.mlx = mlx_init();
    if (game.mlx == NULL)
		return (ft_free_error(&game, "erreur mlx init"));
	ft_printf("mlx init : ok\n");

	//ouvrir la fenetre de jeux
    game.win = mlx_new_window(game.mlx, game.map->width*32, game.map->height*32, "MLX");
    if (game.mlx == NULL)
		return (ft_free_error(&game, "erreur game window"));
	ft_printf("game windows : ok\n");

	// charge les images pour le jeux
	int width;
	int height;
	game.background_img = mlx_xpm_file_to_image(game.mlx, "assets/background.xpm", &width, &height);
	game.wall_img = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &width, &height);
	game.key_img = mlx_xpm_file_to_image(game.mlx, "assets/key.xpm", &width, &height);
	game.hero_img = mlx_xpm_file_to_image(game.mlx, "assets/hero.xpm", &width, &height);
	game.exit_img = mlx_xpm_file_to_image(game.mlx, "assets/exit.xpm", &width, &height);
	ft_printf("game image load : ok\n");

	ft_printf("le jeux ce lance dans ... ba maintenant\n");

	draw_map(&game);

	mlx_hook(game.win, 17, 0, (void *)quit, &game);
	mlx_loop(game.mlx);
	return (FAILURE);
}
