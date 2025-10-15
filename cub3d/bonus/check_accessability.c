/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessability.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:49:42 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	coins_counting(t_game *game, t_dfs *data)
{
	int		solvable;
	int		coin_c;

	coin_c = 0;
	solvable = 0;
	if (game->map.coins_all == 0)
		return (0);
	while (coin_c < game->map.coins_all)
	{
		data->find = game->map.coins[coin_c].position;
		solvable += dfs(*game, game->map.player.position.x, \
			game->map.player.position.y, data);
		clean_matrix(data, *game);
		coin_c++;
	}
	return (solvable);
}

void	check_accessability(t_game *game)
{
	t_dfs	data;
	int		solvable;
	int		i;

	data.visited = ft_calloc(game->map.rows, sizeof(char **));
	i = -1;
	solvable = 0;
	while (++i < game->map.rows)
		data.visited[i] = ft_calloc(game->map.cols + 1, sizeof(char *));
	solvable += coins_counting(game, &data);
	data.find = game->map.exit.position;
	solvable += dfs(*game, game->map.player.position.x, \
		game->map.player.position.y, &data);
	delete_matrix(&data, *game);
	if (solvable != game->map.coins_all + 1)
		ft_error(game, 201);
}
