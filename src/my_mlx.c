/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:33:01 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/05 19:33:11 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_put_image_at(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

void	*my_load_image(t_game *game, char *filename)
{
	int width;
	int height;

	return (mlx_xpm_file_to_image(game->mlx, filename, &width, &height));
}
