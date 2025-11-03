/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:57:54 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/03 14:23:08 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static char	**count_map_lines(char **lines, int start_index)
{
	char	**map_lines;
	int		line_count;
	int		i;
	int		j;

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
		if (ft_strlen(ft_strtrim(lines[i], " \t")) > 0)
		{
			map_lines[j] = ft_strdup(lines[i]);
			j++;
		}
		i++;
	}
	map_lines[j] = NULL;
	return (map_lines);
}

static int	count_map_rows(char **map_grid)
{
	int	count;

	count = 0;
	while (map_grid[count])
		count++;
	return (count);
}

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
	game->map.map_height = count_map_rows(map_grid);
	game->map.map_width = count_longest_line(map_grid);
	game->map.matrix = (int **)map_grid;
	printf("DEBUG: Player position: (%.1f, %.1f)\n", game->player.position.x, game->player.position.y);
	check_border(game);
	check_accessibility(game);
	free_split(lines);
	game->data.map_grid = map_grid;
	return (1);
}
