/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:13 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 20:32:36 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_free(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
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
