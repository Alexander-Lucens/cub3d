/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/07 16:42:01 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void cleanup_graphics(t_game *game)
{
	if (!game || !game->graphics.mlx)
		return;
	if (game->graphics.north.img)
		mlx_destroy_image(game->graphics.mlx, game->graphics.north.img);
	if (game->graphics.south.img)
		mlx_destroy_image(game->graphics.mlx, game->graphics.south.img);
	if (game->graphics.east.img)
		mlx_destroy_image(game->graphics.mlx, game->graphics.east.img);
	if (game->graphics.west.img)
		mlx_destroy_image(game->graphics.mlx, game->graphics.west.img);
	if (game->graphics.buffer.img)
        mlx_destroy_image(game->graphics.mlx, game->graphics.buffer.img);

	game->graphics.north.img = NULL;
	game->graphics.south.img = NULL;
	game->graphics.east.img = NULL;
	game->graphics.west.img = NULL;

	if (game->graphics.window)
		mlx_destroy_window(game->graphics.mlx, game->graphics.window);
	game->graphics.window = NULL;
	mlx_destroy_display(game->graphics.mlx);
	free(game->graphics.mlx);
	game->graphics.mlx = NULL;
}