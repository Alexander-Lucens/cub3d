/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/16 23:33:47 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	do_a_move(t_game *game, t_pos new, t_pos d)
{
	game->player_direction.x = d.x;
	game->player_direction.y = d.y;
	if (new.x < 0 || new.x >= game->map.cols \
		|| new.y < 0 || new.y >= game->map.rows)
		return ;
	if (game->map.matrix[new.y][new.x] == '1')
		return ;
	if (game->map.matrix[new.y][new.x] == 'C')
	{
		game->map.coins_left--;
	}
	game->map.matrix[game->map.player.y][game->map.player.x] = '0';
	game->map.matrix[new.y][new.x] = 'P';
	if (game->map.coins_left == 0)
		game->map.matrix[game->map.exit.y][game->map.exit.x] = 'E';
	game->map.player.x = new.x;
	game->map.player.y = new.y;
	game->moves++;
}

void	move_player(t_game *game, int dx, int dy)
{
	t_pos	new;
	t_pos	d;
	int		moves;

	moves = game->moves;
	new = init_tpos(game->map.player.x + dx, game->map.player.y + dy);
	d = init_tpos(dx, dy);
	do_a_move(game, new, d);
	if (moves != game->moves)
		ft_printf("Moves: %d\n", game->moves);
	if (game->map.player.x == game->map.exit.x && \
		game->map.player.y == game->map.exit.y && game->map.coins_left == 0)
	{
		ft_printf("Congratulations! You finish the game in %d steps.\n", \
			game->moves);
		close_game(game);
	}
	display_game(game);
}
