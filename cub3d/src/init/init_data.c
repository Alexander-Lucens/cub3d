/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/10 23:18:20 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/** 
 * @brief Read file from given fd and allocated and assigned data as a string.
 * All \n and EOF is saved.
 * 
 * @param game 
 * @param fd 
 * @return char* 
 */
char	*read_file(int fd)
{
	char	*out;
	char	*temp;
	char	*line;

	line = get_next_line(fd);
	out = ft_strdup("");
	while (line != NULL)
	{
		temp = ft_strjoin(out, line);
		free(out);
		out = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (out);
}

/**
 * @brief Initialize player data from map grid
 * 
 * @param game Pointer to the main game structure
 * @param map_grid The map grid containing player position
 * @param player_char The character representing the player (N/S/E/W)
 * @param pos_x Player's x position in the map
 * @param pos_y Player's y position in the map
 */
void	init_player_data(t_game *game, char player_char, t_pos pos)
{
	game->player.pos.x = (float)pos.x + 0.5f;
	game->player.pos.y = (float)pos.y + 0.5f;
	if (player_char == 'N')
	{
		game->player.dir = tpos(0, -1);
		game->player.plane = tpos(0.66, 0);
	}
	else if (player_char == 'S')
	{
		game->player.dir = tpos(0, 1);
		game->player.plane = tpos(-0.66, 0);
	}
	else if (player_char == 'E')
	{
		game->player.dir = tpos(1, 0);
		game->player.plane = tpos(0, 0.66);
	}
	else if (player_char == 'W')
	{
		game->player.dir = tpos(-1, 0);
		game->player.plane = tpos(0, -0.66);
	}
}

/**
 * @brief Main initialisation point of the programm.
 * Write in game valid data
 * @param game 
 * @param map_address 
 * @return int 1 on error and int 0 of success. 
 * On error also prints specific error message.
 */
int	init_data(t_game *game, char *map_address)
{
	if (parse_cub_file(game, map_address))
		return (print_error("Parsing failed."));
	if (!game)
		return (print_error("Game structure is not created!"));
	if (testing())
		return (print_error("Invalid parsing."));
	if (init_graphics(game))
		return (print_error("MLX graphic initialisation error."));
	return (0);
}
