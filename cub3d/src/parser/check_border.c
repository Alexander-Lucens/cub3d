/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:02:08 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Could be problem because we not handeling situation where map has unclosed border
// and programm enyway returns nothing
void	check_accessibility(t_game *game)
{
	t_dfs	data;
	int		i;

	i = 0;
	data.visited = malloc(sizeof(int *) * game->map.map_height);
	while (i < game->map.map_height)
	{
		data.visited[i] = ft_calloc(game->map.map_width, sizeof(int));
		i++;
	}
	if (dfs(*game, (int)game->player.pos.x,
			(int)game->player.pos.y, &data)) 
	{
		free_dfs_visited(&data, game->map.map_height);
		return ;
	}
	free_dfs_visited(&data, game->map.map_height);
}

static int	is_on_map_edge(t_game *game, int row, int col)
{
	if (row == 0 || row == game->map.map_height - 1)
		return (1);
	if (col == 0 || col == game->map.map_width - 1)
		return (1);
	if (row > 0 && game->map.matrix[row - 1][col] == CELL_VOID)
		return (1);
	if (row < game->map.map_height - 1 && game->map.matrix[row + 1][col] == CELL_VOID)
		return (1);
	if (col > 0 && game->map.matrix[row][col - 1] == CELL_VOID)
		return (1);
	if (col < game->map.map_width - 1 && game->map.matrix[row][col + 1] == CELL_VOID)
		return (1);
	return (0);
}

void	check_border(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (j < game->map.map_width)
		{
			if ((game->map.matrix[i][j] == CELL_FLOOR
				|| game->map.matrix[i][j] == CELL_PLAYER)
				&& is_on_map_edge(game, i, j))
				return ;
			j++;
		}
		i++;
	}
}