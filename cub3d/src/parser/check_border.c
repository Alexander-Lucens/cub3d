/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/31 17:07:02 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_accessibility(t_game *game)
{
	t_dfs	data;
	int		i;

	i = 0;
	data.visited = malloc(sizeof(int *) * game->map.map_height);
	while (i < game->map.map_height)
	{
		data.visited[i] = calloc(game->map.map_width, sizeof(int));
		i++;
	}
	if (dfs(*game, (int)game->player.position.x,
			(int)game->player.position.y, &data)) 
	{
		free_dfs_visited(&data, game->map.map_height);
		return ;
	}
	free_dfs_visited(&data, game->map.map_height);
}

t_pos	init_tpos(int x, int y)
{
	t_pos	out;

	out.x = x;
	out.y = y;
	return (out);
}

static int	is_on_map_edge(t_game *game, int row, int col)
{
	if (row == 0 || row == game->map.map_height - 1)
		return (1);
	if (col == 0 || col == game->map.map_width - 1)
		return (1);
	if (row > 0 && (game->map.matrix[row - 1][col] == ' '
		|| !game->map.matrix[row - 1][col] == 0))
		return (1);
	if (row < game->map.map_height - 1 && (game->map.matrix[row + 1][col] == ' '
		|| !game->map.matrix[row + 1][col] == 0))
		return (1);
	if (col > 0 && (game->map.matrix[row][col - 1] == ' '
		|| !game->map.matrix[row][col - 1] == 0))
		return (1);
	if (col < game->map.map_width - 1 && (game->map.matrix[row][col + 1] == ' '
		|| !game->map.matrix[row][col + 1] == 0))
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
			if ((game->map.matrix[i][j] == 0
				|| game->map.matrix[i][j] == 'N'
				|| game->map.matrix[i][j] == 'S'
				|| game->map.matrix[i][j] == 'E'
				|| game->map.matrix[i][j] == 'W')
				&& is_on_map_edge(game, i, j))
			{
				return ;
				// ft_error(game, 104);
			}
			j++;
		}
		i++;
	}
}