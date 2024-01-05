/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:13 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 20:51:39 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_free(t_game *game)
{
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	if (game->background_img != NULL)
		mlx_destroy_image(game->mlx, game->background_img);
	if (game->wall_img != NULL)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->hero_img != NULL)
		mlx_destroy_image(game->mlx, game->hero_img);
	if (game->key_img != NULL)
		mlx_destroy_image(game->mlx, game->key_img);
	if (game->exit_img != NULL)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game != NULL)
		free(game->map);
}

void	game_quit(t_game *game)
{
	game_free(game);
	exit(EXIT_SUCCESS);
}

void	game_quit_error(t_game *game, const char *error_msg)
{
	game_free(game);
	ft_printf("Error: %s\n", error_msg);
	exit(EXIT_FAILURE);
}
