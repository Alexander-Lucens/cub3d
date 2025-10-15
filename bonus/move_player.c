/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:51:08 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	do_a_move(t_game *game, t_pos new, t_pos d)
{
	game->map.player.direction = init_tpos(d.x, d.y);
	if (new.x < 0 || new.x >= game->map.cols \
		|| new.y < 0 || new.y >= game->map.rows)
		return ;
	if (game->map.matrix[new.y][new.x] == '1')
		return ;
	if (game->map.matrix[new.y][new.x] == 'C')
	{
		game->map.coins_left--;
	}
	if (game->map.matrix[new.y][new.x] == 'Q')
	{
		game->exit_status = 1;
		close_game(game);
	}
	game->map.matrix[game->map.player.position.y][game->map.player.position.x] \
	= '0';
	game->map.matrix[new.y][new.x] = 'P';
	game->map.player.position = init_tpos(new.x, new.y);
	if (game->map.coins_left == 0)
		game->map.matrix[game->map.exit.position.y][game->map.exit.position.x] \
		= 'E';
	game->moves++;
}

static int	enemies_direction(t_game *g, t_pos *n, t_geo *new)
{
	int	circle;

	circle = 0;
	while (n->x >= 0 && n->y >= 0 && n->x < g->map.cols && n->y < g->map.rows \
		&& g->map.matrix[n->y][n->x] != '0' && g->map.matrix[n->y][n->x] != 'P' \
		&& circle < 3)
	{
		new->direction = init_tpos(-(new->direction.y), new->direction.x);
		circle++;
		*n = init_tpos(new->position.x + new->direction.x, \
			new->position.y + new->direction.y);
	}
	if (n->x < 0 || n->y < 0 || n->x >= g->map.cols || n->y >= g->map.rows \
		|| circle >= 3)
		return (1);
	return (0);
}

static void	enemies_move_loop(t_game *g)
{
	int		i;
	t_pos	n;
	t_geo	new;

	i = -1;
	while (++i < g->map.count_enemies)
	{
		new = g->map.enemies[i];
		n = init_tpos(new.position.x + new.direction.x, \
			new.position.y + new.direction.y);
		if (enemies_direction(g, &n, &new) == 1)
			continue ;
		if (g->map.matrix[n.y][n.x] == 'P')
		{
			g->exit_status = 1;
			close_game(g);
		}
		g->map.matrix[new.position.y][new.position.x] = '0';
		g->map.matrix[n.y][n.x] = 'Q';
		g->map.enemies[i] = init_tgeo(n, new.direction);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	t_pos	new;
	t_pos	d;
	int		moves;

	moves = game->moves;
	new = init_tpos(game->map.player.position.x + dx, \
		game->map.player.position.y + dy);
	d = init_tpos(dx, dy);
	do_a_move(game, new, d);
	enemies_move_loop(game);
	if (game->map.player.position.x == game->map.exit.position.x && \
		game->map.player.position.y == game->map.exit.position.y && \
		game->map.coins_left == 0)
	{
		game->exit_status = 0;
		close_game(game);
	}
}
