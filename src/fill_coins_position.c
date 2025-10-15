/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_coins_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/12 06:32:55 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_coins_position(t_game *game)
{
	int	y;
	int	x;
	int	coin;

	coin = 0;
	game->map.coins = ft_calloc(game->map.coins_all, sizeof(t_pos));
	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (game->map.matrix[y][x] == 'C')
			{
				game->map.coins[coin] = init_tpos(x, y);
				coin++;
			}
		}
	}
}
