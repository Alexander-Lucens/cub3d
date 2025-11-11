/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/11 14:49:23 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check map reachability from player's start using DFS.
 *
 * @param game Pointer to game state (contains map and player)
 * @return 1 if map is closed (success), 0 if player can reach border (error)
 */
int	check_accessibility(t_game *game)
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
		return (print_error("Map is not closed: player can reach border"), 0);
	}
	free_dfs_visited(&data, game->map.map_height);
	return (1);
}

/**
 * @brief Checks if a cell is on the map edge or adjacent to void cell.
 *
 * Used to detect positions that would make the map open/unbounded.
 *
 * @param game Pointer to game state (map matrix and dimensions)
 * @param row Row index of the cell
 * @param col Column index of the cell
 * @return  1 if cell is on/adjacent to edge/void, 0 otherwise
 */
static int	is_on_map_edge(t_game *game, int row, int col)
{
	if (row == 0 || row == game->map.map_height - 1)
		return (1);
	if (col == 0 || col == game->map.map_width - 1)
		return (1);
	if (row > 0 && game->map.matrix[row - 1][col] == CELL_VOID)
		return (1);
	if (row < game->map.map_height - 1
		&& game->map.matrix[row + 1][col] == CELL_VOID)
		return (1);
	if (col > 0 && game->map.matrix[row][col - 1] == CELL_VOID)
		return (1);
	if (col < game->map.map_width - 1
		&& game->map.matrix[row][col + 1] == CELL_VOID)
		return (1);
	return (0);
}

/**
 * @brief Validate that the map border contains only walls.
 * 
 * @param game Pointer to game state (map matrix and dimensions)
 * @return 1 on success (valid border), 0 on failure
 */
int	check_border(t_game *game)
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
				return (
					print_error("Map (border) contains space/floor/player"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
