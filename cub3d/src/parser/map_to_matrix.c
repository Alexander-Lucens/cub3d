/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:17:23 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/04 17:51:54 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Convert a single char to its cell value
 * 
 * @param c Character to convert
 * @return int Cell value according to t_cell enum
 */
static int	char_to_cell(char c)
{
	if (c == '0')
		return (CELL_FLOOR);
	else if (c == '1')
		return (CELL_WALL);
	else if (c == 'N')
		return (CELL_NORTH);
	else if (c == 'S')
		return (CELL_SOUTH);
	else if (c == 'E')
		return (CELL_EAST);
	else if (c == 'W')
		return (CELL_WEST);
	else if (c == ' ')
		return (CELL_VOID);
	else
		return (CELL_VOID);
}

/**
 * @brief Fill a single row of the matrix with converted chars
 * 
 * @param matrix_row The row to fill
 * @param map_line The string line to convert
 * @param width Width of the matrix
 */
static void	fill_matrix_row(int *matrix_row, char *map_line, int width)
{
	int	j;

	j = 0;
	while (j < width && map_line[j])
	{
		matrix_row[j] = char_to_cell(map_line[j]);
		j++;
	}
	while (j < width)
	{
		matrix_row[j] = CELL_VOID;
		j++;
	}
}

/**
 * @brief Convert character map grid to integer matrix for game logic
 * Each character is converted to t_cell enum values
 * 
 * @param map_grid Array of strings of the map
 * @param height Height of the map
 * @param width Width of the map
 * @return int** Integer matrix or NULL on error
 */
int	**convert_map_to_matrix(char **map_grid, int height, int width)
{
	int		**matrix;
	int		i;

	matrix = malloc(sizeof(int *) * height);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = malloc(sizeof(int) * width);
		if (!matrix[i])
		{
			while (--i >= 0)
				free(matrix[i]);
			return (free(matrix), NULL);
		}
		fill_matrix_row(matrix[i], map_grid[i], width);
		i++;
	}
	return (matrix);
}