/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:43:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_images(t_game *game, int size)
{
	game->graphics.background = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/background.xpm", &size, &size);
	game->graphics.border = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/border.xpm", &size, &size);
	game->graphics.coins = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/fish.xpm", &size, &size);
	game->graphics.exit = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/exit.xpm", &size, &size);
	init_img_player1(game, size);
	init_img_player2(game, size);
	init_img_enemy1(game, size);
	init_img_enemy2(game, size);
}

static int	check_graphic_init(t_game *g)
{
	int	i;

	if (!g->graphics.background || !g->graphics.border \
		|| !g->graphics.coins || !g->graphics.exit)
		return (1);
	i = 0;
	while (i < 4)
	{
		if (!g->graphics.player_right[i] || !g->graphics.player_left[i] \
			|| !g->graphics.player_top[i] || !g->graphics.player_bottom[i])
			return (1);
		if (!g->graphics.enemy_right[i] || !g->graphics.enemy_left[i] \
			|| !g->graphics.enemy_top[i] || !g->graphics.enemy_bottom[i])
			return (1);
		i++;
	}
	return (0);
}

void	init_graphics(t_game *game)
{
	int	size;

	size = 32;
	game->map.window_width = game->map.cols * size;
	game->map.window_height = game->map.rows * size;
	init_images(game, size);
	if (check_graphic_init(game) == 1)
		ft_error(game, 103);
	game->graphics.win = mlx_new_window(game->graphics.mlx, \
		game->map.window_width + 100, game->map.window_height, "so_long_bonus");
}
