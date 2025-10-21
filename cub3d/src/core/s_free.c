/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 03:14:25 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	safe_free(void *str)
// {
// 	if (!str)
// 		return ;
// 	free(str);
// }

static void	free_graphic(t_game *game)
{
	if (game->graphics.player_right)
		mlx_destroy_image(game->graphics.mlx, game->graphics.player_right);
	if (game->graphics.player_left)
		mlx_destroy_image(game->graphics.mlx, game->graphics.player_left);
	if (game->graphics.player_top)
		mlx_destroy_image(game->graphics.mlx, game->graphics.player_top);
	if (game->graphics.player_bottom)
		mlx_destroy_image(game->graphics.mlx, game->graphics.player_bottom);
	if (game->graphics.coins)
		mlx_destroy_image(game->graphics.mlx, game->graphics.coins);
	if (game->graphics.exit)
		mlx_destroy_image(game->graphics.mlx, game->graphics.exit);
	if (game->graphics.background)
		mlx_destroy_image(game->graphics.mlx, game->graphics.background);
	if (game->graphics.border)
		mlx_destroy_image(game->graphics.mlx, game->graphics.border);
	game->graphics.player_right = NULL;
	game->graphics.player_left = NULL;
	game->graphics.player_top = NULL;
	game->graphics.player_bottom = NULL;
	game->graphics.coins = NULL;
	game->graphics.exit = NULL;
	game->graphics.background = NULL;
	game->graphics.border = NULL;
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
	free_graphic(game);
	if (game->graphics.win)
		mlx_destroy_window(game->graphics.mlx, game->graphics.win);
	if (game->graphics.mlx)
		mlx_destroy_display(game->graphics.mlx);
	if (game->graphics.mlx)
		free(game->graphics.mlx);
	free(game);
}
