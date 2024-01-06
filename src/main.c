/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:22:50 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/06 14:28:17 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	game->background_img = my_load_image(game, "assets/background.xpm");
	game->wall_img = my_load_image(game, "assets/wall.xpm");
	game->key_img = my_load_image(game, "assets/key.xpm");
	game->hero_img = my_load_image(game, "assets/hero.xpm");
	game->exit_img = my_load_image(game, "assets/exit.xpm");
}

void	move_player(t_game *game, int x, int y)
{
	char	where;
	int		position;

	position = my_coord(game, game->map->player_x + x, game->map->player_y + y);
	where = game->map->bytes[position];
	if (where == 'C')
	{
		game->map->bytes[position] = '0';
		game->map->coin_count--;
	}
	if (where == '0' || where == 'C')
	{
		my_put_image_at(game, game->background_img,
			game->map->player_x, game->map->player_y);
		game->map->player_x += x;
		game->map->player_y += y;
		my_put_image_at(game, game->hero_img,
			game->map->player_x, game->map->player_y);
		game->move_count++;
		ft_printf("\033[0;32mmove : %d\n", game->move_count);
	}
	if (where == 'E')
		if (game->map->coin_count == 0)
			game_quit(game);
}

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		game_quit(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
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
				my_put_image_at(game, game->wall_img, x, y);
			else if (game->map->bytes[y * game->map->width + x] == '0')
				my_put_image_at(game, game->background_img, x, y);
			else if (game->map->bytes[y * game->map->width + x] == 'C')
				my_put_image_at(game, game->key_img, x, y);
			else if (game->map->bytes[y * game->map->width + x] == 'E')
				my_put_image_at(game, game->exit_img, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game.move_count = 0;
	game.map = load_map(argv[1]);
	if (game.map == NULL)
		game_quit_error(&game, "erreur de map");
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		game_quit_error(&game, "erreur mlx init");
	game.win = mlx_new_window(game.mlx, game.map->width * 32,
			game.map->height * 32, "so_long");
	if (game.win == NULL)
		game_quit_error(&game, "erreur game window");
	load_images(&game);
	draw_map(&game);
	my_put_image_at(&game, game.hero_img, game.map->player_x,
		game.map->player_y);
	mlx_hook(game.win, 17, 0, (void *)game_quit, &game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_loop(game.mlx);
	return (FAILURE);
}
