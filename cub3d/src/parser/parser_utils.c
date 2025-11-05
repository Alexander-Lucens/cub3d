/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:17:45 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/04 18:14:23 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checker for white spaces and end of string
 * 
 * @return int * 
 */
int	check_white_spaces_end_of_str(char **lines, int *i)
{
	int	j;

	if (lines[*i][0] == '\0')
	{
		(*i)++;
		return (1);
	}
	j = 0;
	while (lines[*i][j])
	{
		if (lines[*i][j] != ' ' && lines[*i][j] != '\t'
			&& lines[*i][j] != '\n')
			return (0);
		j++;
	}
	(*i)++;
	return (1);
}

void	free_dfs_visited(t_dfs *data, int rows)
{
	int	i;

	i = 0;
	if (!data->visited)
		return ;
	while (i < rows)
	{
		free(data->visited[i]);
		i++;
	}
	free(data->visited);
	data->visited = NULL;
}

/**
 * @brief Validates all struct values exist
 * 
 * @return int * 
 */
int	validate_all_data(t_game *game)
{
	if (!game->data.north_texture_path
		|| !game->data.south_texture_path
		|| !game->data.east_texture_path
		|| !game->data.west_texture_path)
		return (0);
	if (!game->data.floor || !game->data.ceiling)
		return (0);
	return (1);
}

void	check_map_extension(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i >= 4 && ft_strncmp(map + i - 4, ".cub", 4) != 0)
		ft_error(NULL, 1);
}

int	count_lines(char **lines, int start_idx)
{
	int		line_count;
	char	*trimmed;

	line_count = 0;
	while (lines[start_idx])
	{
		trimmed = ft_strtrim(lines[start_idx], " \t");
		if (ft_strlen(trimmed) > 0)
			line_count++;
		free(trimmed);
		start_idx++;
	}
	return (line_count);
}

