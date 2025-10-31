/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:10:47 by lkramer           #+#    #+#             */
/*   Updated: 2025/10/31 17:24:11 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	valid_map_chars(char **map_grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			c = map_grid[i][j];
			if (c != '0' && c != '1' && c != 'N'
				&& c != 'S' && c != 'E' && c != 'W'
				&& c != ' ' && c != '\t')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	single_player(char **map_grid)
{
	int		i;
	int		j;
	int		num_player;
	char	c;

	i = 0;
	num_player = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			c = map_grid[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				num_player++;
			j++;
		}
		i++;
	}
	return (num_player == 1);
}

static int	player_info(t_game *game, char **map_grid)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			c = map_grid[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				game->player.position.x = (float)j;
				game->player.position.y = (float)i;
				if (c == 'N')
					game->player.direction = init_tpos(0, -1);
				else if (c == 'S')
					game->player.direction = init_tpos(0, 1);
				else if (c == 'E')
					game->player.direction = init_tpos(1, 0);
				else if (c == 'W')
					game->player.direction = init_tpos(-1, 0);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_map(t_game *game, char **map_grid)
{
	if (!valid_map_chars(map_grid))
	{
		printf("valid_map_chars FAILED\n");
		return (0);
	}
	if (!single_player(map_grid))
	{
		printf("single player FAILED\n");
		return (0);
	}
	if (!player_info(game, map_grid))
	{
		printf("player info FAILED\n");
		return (0);
	}
	return (1);
}
