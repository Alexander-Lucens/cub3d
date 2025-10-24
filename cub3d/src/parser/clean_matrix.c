/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 05:05:38 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clean_matrix(t_dfs *data, t_game game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game.map.rows)
	{
		j = -1;
		while (++j < game.map.cols)
			data->visited[i][j] = 0;
	}
}

void	delete_matrix(t_dfs *data, t_game game)
{
	int	i;

	i = -1;
	while (++i < game.map.rows)
		free(data->visited[i]);
	free(data->visited);
}
