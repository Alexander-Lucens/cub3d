/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 05:05:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Could be used but need to make changes
 * 
 */
int	dfs(t_game game, int x, int y, t_dfs *data)
{
	int	result;

	result = 0;
	if (x < 0 || y < 0 || x >= game.map.cols || y >= game.map.rows)
		return (0);
	if (game.map.matrix[y][x] == '1' || data->visited[y][x] == 'X')
		return (0);
	if (x == data->find.x && y == data->find.y)
		return (1);
	data->visited[y][x] = 'X';
	if (dfs(game, x + 1, y, data) == 1 || dfs(game, x - 1, y, data) \
		|| dfs(game, x, y + 1, data) || dfs(game, x, y - 1, data))
		result = 1;
	return (result);
}
