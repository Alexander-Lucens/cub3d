/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 15:12:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_images(t_game *game, int size)
{
	game->graphics.background = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/background.xpm", &size, &size);
	game->graphics.border = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/border.xpm", &size, &size);
	game->graphics.coins = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/fish.xpm", &size, &size);
	game->graphics.exit = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/exit.xpm", &size, &size);
	game->graphics.player_right = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_right.xpm", &size, &size);
	game->graphics.player_left = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_left.xpm", &size, &size);
	game->graphics.player_top = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_top.xpm", &size, &size);
	game->graphics.player_bottom = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_bottom.xpm", &size, &size);
}

void	init_graphics(t_game *game)
{
	int	size;

	size = 32;
	game->map.window_width = game->map.cols * size;
	game->map.window_height = game->map.rows * size;
	init_images(game, size);
	if (!game->graphics.background || !game->graphics.border \
		|| !game->graphics.coins || !game->graphics.exit \
		|| !game->graphics.player_right || !game->graphics.player_left \
		|| !game->graphics.player_top || !game->graphics.player_bottom)
		ft_error(game, 102);
	game->graphics.win = mlx_new_window(game->graphics.mlx, \
		game->map.window_width, game->map.window_height, "so_long");
}
