/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 10:51:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static void	do_a_move(t_game *game, t_pos new, t_pos d)
// {
// 	game->player_direction.x = d.x;
// 	game->player_direction.y = d.y;
// 	if (new.x < 0 || new.x >= game->map.cols || new.y < 0 || new.y >= game->map.rows)
// 		return ;
// 	if (game->map.matrix[new.y][new.x] == '1')
// 		return ;
// 	if (game->map.matrix[new.y][new.x] == 'C')
// 	{
// 		game->map.coins_left--;
// 	}
// 	game->map.matrix[game->map.player.y][game->map.player.x] = '0';
// 	game->map.matrix[new.y][new.x] = 'P';
// 	if (game->map.coins_left == 0)
// 		game->map.matrix[game->map.exit.y][game->map.exit.x] = 'E';
// 	game->map.player.x = new.x;
// 	game->map.player.y = new.y;
// 	game->moves++;
// }

// void	move_player(t_game *game, int dx, int dy)
// {
// 	t_pos	new;
// 	t_pos	d;

// 	new = init_tpos(game->map.player.x + dx, game->map.player.y + dy);
// 	d = init_tpos(dx, dy);
// 	do_a_move(game, new, d);

// 	// TODO - make display_game_2d(game) to show it from the top and throw reys in to the walls
// 	// display_game_2d(game);
// 	// Then
// 	// TODO - make render(game); That mean render - is modification for display_game();
// 	display_game(game);
// }
