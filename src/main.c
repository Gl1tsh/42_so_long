/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 07:22:50 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/03 18:58:58 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}


void	draw_map(t_map *map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 32, y * 32);
			else if (map->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;




	//initialiser la mz lib
    game.mlx = mlx_init();
    if (game.mlx == NULL)
		return (ft_free_error(&map, "erreur mlx init"));

	//ouvrir la fenetre de jeux
    game.win = mlx_new_window(game.mlx, 800, 600, "MLX");
    if (game.mlx == NULL)
		return (ft_free_error(&map, "erreur game window"));

	// charge les images pour le jeux
	int width;
	int height;
	game.background_img = mlx_xpm_file_to_image(game.mlx, "background.xpm", &width, &height);
	game.wall_img = mlx_xpm_file_to_image(game.mlx, "wall.xpm", &width, &height);
	printf("background_img %p\nwall_img %p\n", game.background_img, game.wall_img);

	draw_map(&map, &game);

	mlx_hook(game.win, 17, 0, (void *)quit, &game);
	mlx_loop(game.mlx);
	return (FAILURE);

	//debug_mode(&map_info);
	// lancer le jeu
	// liberer toutes les donnees et fermer proprement
}








// static void debug_mode(t_map *map)
// {
// 	printf("map:\n");
// 	for (int i = 0; i < map->map_hauteur; i++) {
// 		printf("%s\n", map->map[i]);
// 	}
// 	printf("map_copy:\n");
// 	for (int i = 0; i < map->map_hauteur; i++) {
// 		printf("%s\n", map->map_copy[i]);
// 	}
// 	printf("map_hauteur: %d\n", map->map_hauteur);
// 	printf("map_largeur: %d\n", map->map_largeur);
// 	printf("player_x: %d\n", map->player_x);
// 	printf("player_y: %d\n", map->player_y);
// 	printf("exit_x: %d\n", map->exit_x);
// 	printf("exit_y: %d\n", map->exit_y);
// 	printf("nbr_coin: %d\n", map->nbr_coin);
// 	return ;
// }

/* test open windows
int main()
{
	void	*mlx;
	void	*mlx_win;

	t_info	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 500, "Hello World!");

	img.img = mlx_new_image(mlx, 800, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);

	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);

}
*/