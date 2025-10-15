/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:41:46 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:43:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_img_player1(t_game *game, int size)
{
	game->graphics.player_right[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_right_1.xpm", &size, &size);
	game->graphics.player_right[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_right_0.xpm", &size, &size);
	game->graphics.player_right[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_right_2.xpm", &size, &size);
	game->graphics.player_right[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_right_0.xpm", &size, &size);
	game->graphics.player_left[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_left_1.xpm", &size, &size);
	game->graphics.player_left[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_left_0.xpm", &size, &size);
	game->graphics.player_left[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_left_2.xpm", &size, &size);
	game->graphics.player_left[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_left_0.xpm", &size, &size);
}

void	init_img_player2(t_game *game, int size)
{
	game->graphics.player_top[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_top_1.xpm", &size, &size);
	game->graphics.player_top[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_top_0.xpm", &size, &size);
	game->graphics.player_top[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_top_2.xpm", &size, &size);
	game->graphics.player_top[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_top_0.xpm", &size, &size);
	game->graphics.player_bottom[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_bottom_0.xpm", &size, &size);
	game->graphics.player_bottom[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_bottom_1.xpm", &size, &size);
	game->graphics.player_bottom[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_bottom_0.xpm", &size, &size);
	game->graphics.player_bottom[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/player_bottom_2.xpm", &size, &size);
}

void	init_img_enemy1(t_game *game, int size)
{
	game->graphics.enemy_right[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_right_0.xpm", &size, &size);
	game->graphics.enemy_right[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_right_1.xpm", &size, &size);
	game->graphics.enemy_right[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_right_0.xpm", &size, &size);
	game->graphics.enemy_right[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_right_2.xpm", &size, &size);
	game->graphics.enemy_left[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_left_0.xpm", &size, &size);
	game->graphics.enemy_left[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_left_1.xpm", &size, &size);
	game->graphics.enemy_left[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_left_0.xpm", &size, &size);
	game->graphics.enemy_left[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_left_2.xpm", &size, &size);
}

void	init_img_enemy2(t_game *game, int size)
{
	game->graphics.enemy_top[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_top_0.xpm", &size, &size);
	game->graphics.enemy_top[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_top_1.xpm", &size, &size);
	game->graphics.enemy_top[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_top_0.xpm", &size, &size);
	game->graphics.enemy_top[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_top_2.xpm", &size, &size);
	game->graphics.enemy_bottom[0] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_bottom_0.xpm", &size, &size);
	game->graphics.enemy_bottom[1] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_bottom_1.xpm", &size, &size);
	game->graphics.enemy_bottom[2] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_bottom_0.xpm", &size, &size);
	game->graphics.enemy_bottom[3] = mlx_xpm_file_to_image(game->graphics.mlx, \
		"textures/enemy_bottom_2.xpm", &size, &size);
}
