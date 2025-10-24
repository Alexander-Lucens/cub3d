/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_str_to_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 05:05:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Fill position of player and exit 
 * and if one of them is already exist --> throws error
 */
static void	fill_if_empty(t_game *game, t_pos pos, char x)
{
	if (game->map.exit.x == -1 && game->map.exit.y == -1 && x == 'E')
	{
		game->map.matrix[pos.y][pos.x] = x;
		game->map.exit = pos;
		return ;
	}
	if (game->map.player.x == -1 && game->map.player.y == -1 && x == 'P')
	{
		game->map.matrix[pos.y][pos.x] = x;
		game->map.player = pos;
		return ;
	}
	ft_error(game, 204);
}

static void	filler(t_game *game, int i, int j, int x)
{
	game->map.matrix[i][j] = '0';
	if (game->map.map[x] == '1')
		game->map.matrix[i][j] = '1';
	else if (game->map.map[x] == 'P')
	{
		fill_if_empty(game, init_tpos(j, i), 'P');
	}
	else if (game->map.map[x] == 'C')
	{
		game->map.matrix[i][j] = 'C';
		game->map.coins_all++;
	}
	else if (game->map.map[x] == 'E')
	{
		fill_if_empty(game, init_tpos(j, i), 'E');
	}
	else if (game->map.map[x] != '0')
	{
		ft_error(game, 102);
	}
}

static void	processing_line(t_game *game, int i)
{
	int	j;
	int	x;

	j = -1;
	x = 0;
	game->map.matrix[i] = ft_calloc(game->map.cols, sizeof(int));
	while (++j < game->map.cols)
	{
		if (x >= 0 && x < (game->map.cols + 1) * game->map.rows)
		{
			x = i * (game->map.cols + 1) + j;
			filler(game, i, j, x);
		}
		else
		{
			ft_error(game, 102);
		}
	}
}

void	map_str_to_matrix(t_game *game)
{
	int	i;

	game->map.coins_all = 0;
	i = 0;
	game->map.player = init_tpos(-1, -1);
	game->map.exit = init_tpos(-1, -1);
	game->map.matrix = ft_calloc(game->map.rows, sizeof(char *));
	while (i >= 0 && i < game->map.rows)
	{
		processing_line(game, i);
		i++;
	}
	if (game->map.coins_all == 0)
		ft_error(game, 205);
	game->map.coins_left = game->map.coins_all;
	fill_coins_position(game);
	if (game->map.player.x == -1 && game->map.player.y == -1)
		ft_error(game, 200);
	if (game->map.exit.x == -1 && game->map.exit.y == -1)
		ft_error(game, 202);
	check_border(game);
	check_accessability(game);
}
