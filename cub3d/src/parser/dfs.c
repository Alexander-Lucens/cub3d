/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/**
 * Could be used but need to make changes
 * 
 */
int	dfs(t_game game, int x, int y, t_dfs *data)
{
	if (x == 0 || y == 0 || x == game.map.map_width - 1
		|| y == game.map.map_height - 1)
		return (1);
	data->visited[y][x] = 1;
	if (x > 0 && !data->visited[y][x - 1]
			&& is_walkable(game.map.matrix[y][x - 1]))
		if (dfs(game, x - 1, y, data))
			return (1);
	if (x < game.map.map_width - 1 && !data->visited[y][x + 1]
			&& is_walkable(game.map.matrix[y][x + 1]))
		if (dfs(game, x + 1, y, data))
			return (1);
	if (y > 0 && !data->visited[y - 1][x]
		&& is_walkable(game.map.matrix[y - 1][x]))
		if (dfs(game, x, y - 1, data))
			return (1);
	if (y < game.map.map_height - 1 && !data->visited[y + 1][x]
		&& is_walkable(game.map.matrix[y + 1][x]))
		if (dfs(game, x, y + 1, data))
			return (1);
	return (0);
}
