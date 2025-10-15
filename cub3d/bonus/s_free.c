/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:43:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	free_palyer(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->graphics.player_right[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.player_right[i]);
		if (game->graphics.player_left[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.player_left[i]);
		if (game->graphics.player_top[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.player_top[i]);
		if (game->graphics.player_bottom[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.player_bottom[i]);
	}
}

static void	free_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (game->graphics.enemy_right[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.enemy_right[i]);
		if (game->graphics.enemy_left[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.enemy_left[i]);
		if (game->graphics.enemy_top[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.enemy_top[i]);
		if (game->graphics.enemy_bottom[i])
			mlx_destroy_image(game->graphics.mlx, \
				game->graphics.enemy_bottom[i]);
	}
}

static void	free_graphic(t_game *game)
{
	free_enemies(game);
	free_palyer(game);
	if (game->graphics.background)
		mlx_destroy_image(game->graphics.mlx, \
			game->graphics.background);
	if (game->graphics.border)
		mlx_destroy_image(game->graphics.mlx, \
			game->graphics.border);
	if (game->graphics.coins)
		mlx_destroy_image(game->graphics.mlx, \
			game->graphics.coins);
	if (game->graphics.exit)
		mlx_destroy_image(game->graphics.mlx, \
			game->graphics.exit);
}

void	s_free(t_game *game)
{
	int	i;

	if (!game)
		return ;
	if (game->map.map) 
		free(game->map.map);
	i = -1;
	if (game->map.matrix)
	{
		while (++i < game->map.rows)
			free(game->map.matrix[i]);
		free(game->map.matrix);
	}
	if (game->map.coins)
		free(game->map.coins);
	if (game->map.enemies)
		free(game->map.enemies);
	free_graphic(game);
	if (game->graphics.win)
		mlx_destroy_window(game->graphics.mlx, game->graphics.win);
	if (game->graphics.mlx)
		mlx_destroy_display(game->graphics.mlx);
	if (game->graphics.mlx)
		free(game->graphics.mlx);
	free(game);
}
