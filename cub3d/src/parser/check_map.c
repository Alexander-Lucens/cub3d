/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:10:47 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/11 14:35:08 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Find starting index of the map grid
 * 
 * @param lines Array of strings representing lines of the .cub file
 * @return int Index where map grid starts, or -1 if invalid structure
 */
int	validate_start_idx(char **lines)
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
		else
			return (print_error("Invalid line in file"), -1);
		i++;
	}
	return (-1);
}

/**
 * @brief Checks valid map characters
 * @param lines Array of strings lines of the .cub file
 * @return 1 on success and 
 * 0 on error when invalid char is found * 
 */
static int	valid_map_chars(char **lines)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			c = lines[i][j];
			if (c != '0' && c != '1' && c != 'N'
				&& c != 'S' && c != 'E' && c != 'W'
				&& c != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Checks for single player on map
 * @param lines Array of strings all lines of the .cub file
 * @return 1 on success when only one playe is found 
 * and 0 on error no or more are found * 
 */
static int	single_player(char **lines)
{
	int		i;
	int		j;
	int		num_player;
	char	c;

	i = 0;
	num_player = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			c = lines[i][j];
			if (ft_strchr("NSEW", c) != NULL)
				num_player++;
			j++;
		}
		i++;
	}
	return (num_player == 1);
}

/**
 * @brief Checks for player starting position
 * @param lines Array of strings all lines of the .cub file
 * @return 1 on success when player is found and 
 * 0 on error no player found * 
 */
static int	player_info(t_game *game, char **lines)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			c = lines[i][j];
			if (ft_strchr("NSEW", c) != NULL)
			{
				init_player_data(game, c, tpos((float) j, (float) i));
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Main caller to validate map info
 * @param lines Array of strings all lines of the .cub file
 * @return 1 on success and 0 on error  * 
 */
int	valid_map(t_game *game, char **lines)
{
	if (!valid_map_chars(lines))
		return (print_error("check_map: valid_map_chars FAILED"), 0);
	if (!single_player(lines))
		return (print_error("check_map: single player FAILED"), 0);
	if (!player_info(game, lines))
		return (print_error("check_map: player info FAILED"), 0);
	return (1);
}
