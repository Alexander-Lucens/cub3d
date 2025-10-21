/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 03:15:58 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	*player_direction(t_game *game)
{
	if (game->player_direction.x == -1 && game->player_direction.y == 0)
		return (game->graphics.player_left);
	if (game->player_direction.x == 0 && game->player_direction.y == 1)
		return (game->graphics.player_top);
	if (game->player_direction.x == 0 && game->player_direction.y == -1)
		return (game->graphics.player_bottom);
	return (game->graphics.player_right);
}

static void	*img_assignation(t_game *game, int x, int y)
{
	if (game->map.matrix[y][x] == '1')
		return (game->graphics.border);
	else if (game->map.matrix[y][x] == 'C')
		return (game->graphics.coins);
	else if (game->map.matrix[y][x] == 'E' && game->map.coins_left == 0)
		return (game->graphics.exit);
	else if (game->map.matrix[y][x] == 'P')
		return (player_direction(game));
	return (game->graphics.background);
}

void	display_game(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	mlx_clear_window(game->graphics.mlx, game->graphics.win);
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			img = img_assignation(game, x, y);
			mlx_put_image_to_window(game->graphics.mlx, \
				game->graphics.win, img, x * SEGMENT_SIZE, y * SEGMENT_SIZE);
		}
	}
}
