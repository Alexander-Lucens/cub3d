/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/11 14:26:21 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Checks whether a map cell is traversable
 * @returns 1 when cell is walkable (floor or player),
 * otherwise 0.
 */
static int	is_walkable(int cell)
{
	return (cell == CELL_FLOOR || cell == CELL_PLAYER);
}

/**
 * Depth-first search to detect map border leaks
 * @game: current game state containing the map matrix - dimensions
 * @x: starting x coordinate for the search
 * @y: starting y coordinate for the search
 * @data: DFS data (visited matrix)
 *
 * @return 1 if search reaches outer border 
 * (indicating an open/invalid map),
 * otherwise returns 0.
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
