/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:54:13 by nagiorgi          #+#    #+#             */
/*   Updated: 2024/01/03 19:14:38 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(t_game *game)
{
	free(game->map);
	return (SUCCESS);
}

int	ft_free_error(t_game *game, const char *error_msg)
{
	ft_free(game);
	ft_printf("Error: %s\n", error_msg);
	return (FAILURE);
}
