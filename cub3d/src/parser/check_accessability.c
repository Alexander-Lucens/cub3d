/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessability.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 17:29:43 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


/* void	check_accessability(t_game *game)
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
	data.find = game->map.exit;
	solvable += dfs(*game, game->map.player.x, game->map.player.y, &data);
	delete_matrix(&data, *game);
	if (solvable != game->map.coins_all + 1)
		ft_error(game, 201);
} */
