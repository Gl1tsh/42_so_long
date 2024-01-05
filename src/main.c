/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:22:50 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 19:25:15 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return 0;
}

void	move_player(t_game *game, int x, int y)
{
	char	where;

	where = game->map->bytes[(game->map->player_y + y) * game->map->width + (game->map->player_x + x)];

	if (where == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, game->map->player_x * 32, game->map->player_y * 32);
		game->map->player_x += x;
		game->map->player_y += y;
		mlx_put_image_to_window(game->mlx, game->win, game->hero_img, game->map->player_x * 32, game->map->player_y * 32);
	}
	else if (where == 'C')
	{
		game->map->bytes[(game->map->player_y + y) * game->map->width + (game->map->player_x + x)] = '0';
		game->map->coin_count--;
		mlx_put_image_to_window(game->mlx, game->win, game->background_img, game->map->player_x * 32, game->map->player_y * 32);
		game->map->player_x += x;
		game->map->player_y += y;
		mlx_put_image_to_window(game->mlx, game->win, game->hero_img, game->map->player_x * 32, game->map->player_y * 32);
	}
	else if (where == 'E')
	{
		if (game->map->coin_count == 0)
			quit(game);
	}
	game->move_count++;
	ft_printf("move : %d\n", game->move_count);
}

int key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("Merci d'avoir jouer\n");
		quit(game);
	}
	else if (keycode == KEY_W)
		move_player(game,  0, -1);
	else if (keycode == KEY_S)
		move_player(game,  0, 1);
	else if (keycode == KEY_A)
		move_player(game,  -1, 0);
	else if (keycode == KEY_D)
		move_player(game,  1, 0);
	return 0;
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

	game.move_count = 0;
	game.map = load_map(argv[1]);
	if (game.map == NULL)
		return (ft_free_error(&game, "erreur de map"));

	//initialiser la mz lib
    game.mlx = mlx_init();
    if (game.mlx == NULL)
		return (ft_free_error(&game, "erreur mlx init"));

	//ouvrir la fenetre de jeux
    game.win = mlx_new_window(game.mlx, game.map->width*32, game.map->height*32, "MLX");
    if (game.mlx == NULL)
		return (ft_free_error(&game, "erreur game window"));

	// charge les images pour le jeux
	int width;
	int height;
	game.background_img = mlx_xpm_file_to_image(game.mlx, "assets/background.xpm", &width, &height);
	game.wall_img = mlx_xpm_file_to_image(game.mlx, "assets/wall.xpm", &width, &height);
	game.key_img = mlx_xpm_file_to_image(game.mlx, "assets/key.xpm", &width, &height);
	game.hero_img = mlx_xpm_file_to_image(game.mlx, "assets/hero.xpm", &width, &height);
	game.exit_img = mlx_xpm_file_to_image(game.mlx, "assets/exit.xpm", &width, &height);

	draw_map(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.hero_img, game.map->player_x * 32, game.map->player_y * 32);

	mlx_hook(game.win, 17, 0, (void *)quit, &game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_loop(game.mlx);
	return (FAILURE);
}
