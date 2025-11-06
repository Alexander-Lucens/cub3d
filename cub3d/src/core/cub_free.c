/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 17:16:13 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * @brief Free the integer matrix allocated for the game map
 * 
 * @param matrix The matrix to free
 * @param height Number of rows in the matrix
 */
void	free_matrix(int **matrix, int height)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

/**
 * @brief Free all allocated memory in t_game structure
 * 
 * @param game The game structure to free
 */
void	s_free(t_game *game)
{
	if (!game)
		return ;

	cleanup_graphics(game);
	if (game->data.floor)
		c_free(game->data.floor);
	if (game->data.ceiling)
		c_free(game->data.ceiling);
	if (game->data.north_texture_path)
		free(game->data.north_texture_path);
	if (game->data.south_texture_path)
		free(game->data.south_texture_path);
	if (game->data.east_texture_path)
		free(game->data.east_texture_path);
	if (game->data.west_texture_path)
		free(game->data.west_texture_path);
	if (game->data.map_grid)
		free_split(game->data.map_grid);
	if (game->map.matrix)
		free_matrix(game->map.matrix, game->map.map_height);
	if (game)
		free(game);
}


/**
 * @brief Free all allocated memory in t_game structure
 * 
 * @param game The game structure to free
 */
void	c_free(t_rgb *color)
{
	if (!color)
		return ;
	free(color);
}

