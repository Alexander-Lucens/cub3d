/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:57:54 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/04 17:59:27 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Find the starting index of the map grid in the file content
 * 
 * This function scans through the file lines to find where the map grid starts.
 * 
 * @param lines Array of strings representing each line of the .cub file
 * @return int Index where map grid starts, or -1 if invalid structure
 */
static int	validate_start_idx(char **lines)
{
	int	i;
	int	elements_found;

	i = 0;
	elements_found = 0;
	while (lines[i])
	{
		if (check_white_spaces_end_of_str(lines, &i))
			continue ;
		if (ft_strncmp(lines[i], "NO ", 3) == 0
			|| ft_strncmp(lines[i], "SO ", 3) == 0
			|| ft_strncmp(lines[i], "WE ", 3) == 0
			|| ft_strncmp(lines[i], "EA ", 3) == 0
			|| ft_strncmp(lines[i], "F ", 2) == 0
			|| ft_strncmp(lines[i], "C ", 2) == 0)
			elements_found++;
		else if (elements_found == 6)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Extract and create array of map lines from the file content
 * 
 * Creates a new array containing only the map grid lines,
 * starting from the specified index. Each valid map line
 * is duplicated to create an own array.
 * 
 * @param lines Array of all file lines
 * @param start_index Index where map grid begins
 * @return char** Array of map line strings, NULL-terminated, or NULL on error
 */
static char	**count_map_lines(char **lines, int start_index)
{
	char	**map_lines;
	int		line_count;
	int		i;
	int		j;
	char	*trimmed;

	line_count = count_lines(lines, start_index);
	if (line_count == 0)
		return (NULL);
	map_lines = malloc(sizeof(char *) * (line_count + 1));
	if (!map_lines)
		return (NULL);
	i = start_index;
	j = 0;
	while (lines[i] && j < line_count)
	{
		trimmed = ft_strtrim(lines[i], " \t");
		if (ft_strlen(trimmed) > 0)
		{
			map_lines[j] = ft_strdup(lines[i]);
			j++;
		}
		free(trimmed);
		i++;
	}
	map_lines[j] = NULL;
	return (map_lines);
}

/**
 * @brief Count the number of rows in the map grid
 * 
 * @param map_grid NULL-terminated array of map line strings
 * @return int Number of rows in the map
 */
static int	count_map_rows(char **map_grid)
{
	int	count;

	count = 0;
	while (map_grid[count])
		count++;
	return (count);
}

/**
 * @brief Find the width of the longest line in the map grid
 * 
 * @param map_grid NULL-terminated array of map line strings
 * @return int Length of the longest line (map width)
 */
static int	count_longest_line(char **map_grid)
{
	int	max_len;
	int	current_len;
	int	i;

	max_len = 0;
	i = 0;
	while (map_grid[i])
	{
		current_len = ft_strlen(map_grid[i]);
		if (current_len > max_len)
			max_len = current_len;
		i++;
	}
	return (max_len);
}

/**
 * @brief Parse and validate the map grid from file content
 * 
 * Populates game->data.map_grid (char**) for render logic
 * and game->map.matrix (int**) for game logic.
 * 
 * @param game Pointer to the main game structure to populate
 * @param content Raw file content as a single string
 * @return int 1 on success, 0 on failure
 */
int	parse_map_grid(t_game *game, char *content)
{
	char	**lines;
	char	**map_grid;
	int		map_start_idx;

	lines = ft_split(content, '\n');
	if (!lines)
		return (0);
	map_start_idx = validate_start_idx(lines);
	if (map_start_idx == -1)
		return (free_split(lines), 0);
	map_grid = count_map_lines(lines, map_start_idx);
	if (!map_grid)
		return (free_split(lines), 0);
	if (!valid_map(game, map_grid))
		return (free_split(lines), free_split(map_grid), 0);
	game->data.map_grid = map_grid;
	game->map.map_height = count_map_rows(map_grid);
	game->map.map_width = count_longest_line(map_grid);
	game->map.matrix = convert_map_to_matrix(map_grid, game->map.map_height,
			game->map.map_width);
	check_border(game);
	check_accessibility(game);
	free_split(lines);
	game->data.map_grid = map_grid;
	return (1);
}
