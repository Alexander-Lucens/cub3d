/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:48:45 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	*enemy_direction(t_game *game, int x, int y)
{
	int	index;

	index = 0;
	while (index < game->map.count_enemies \
		&& game->map.enemies[index].position.x != x \
		&& game->map.enemies[index].position.y != y)
		index++;
	if (game->map.enemies[index].direction.x == -1 \
		&& game->map.enemies[index].direction.y == 0)
		return (game->graphics.enemy_left[game->graphics.sprites_counter]);
	if (game->map.enemies[index].direction.x == 0 \
		&& game->map.enemies[index].direction.y == 1)
		return (game->graphics.enemy_top[game->graphics.sprites_counter]);
	if (game->map.enemies[index].direction.x == 0 \
		&& game->map.enemies[index].direction.y == -1)
		return (game->graphics.enemy_bottom[game->graphics.sprites_counter]);
	return (game->graphics.enemy_right[game->graphics.sprites_counter]);
}

static void	*player_direction(t_game *game)
{
	if (game->map.player.direction.x == -1 \
		&& game->map.player.direction.y == 0)
		return (game->graphics.player_left[game->graphics.sprites_counter]);
	if (game->map.player.direction.x == 0 \
		&& game->map.player.direction.y == 1)
		return (game->graphics.player_top[game->graphics.sprites_counter]);
	if (game->map.player.direction.x == 0 \
		&& game->map.player.direction.y == -1)
		return (game->graphics.player_bottom[game->graphics.sprites_counter]);
	return (game->graphics.player_right[game->graphics.sprites_counter]);
}

static void	*img_assignation(t_game *game, int x, int y)
{
	if (game->map.matrix[y][x] == '1')
		return (game->graphics.border);
	else if (game->map.matrix[y][x] == 'C')
		return (game->graphics.coins);
	else if (game->map.matrix[y][x] == 'Q')
		return (enemy_direction(game, x, y));
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
	show_info(game);
}
