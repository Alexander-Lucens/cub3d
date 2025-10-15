/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coins_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:43:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	fill_coins_position(t_game *game)
{
	int	y;
	int	x;
	int	coin;

	coin = 0;
	game->map.coins = ft_calloc(game->map.coins_all, sizeof(t_geo));
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (game->map.matrix[y][x] == 'C')
			{
				game->map.coins[coin] = init_tgeo(init_tpos(x, y), \
				init_tpos(0, 0));
				coin++;
			}
		}
	}
}

void	fill_enemies_position(t_game *game)
{
	int	y;
	int	x;
	int	en;

	en = 0;
	game->map.enemies = ft_calloc(game->map.count_enemies, sizeof(t_geo));
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (game->map.matrix[y][x] == 'Q')
			{
				game->map.enemies[en] = init_tgeo(init_tpos(x, y), \
				init_tpos(1, 0));
				en++;
			}
		}
	}
}
