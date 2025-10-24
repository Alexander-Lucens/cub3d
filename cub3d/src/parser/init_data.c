/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 19:07:03 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Not needed because maps will be not rectangular
 * 
 */
// static void	check_ordinarity_of_lines(t_game *game)
// {
// 	int	row;
// 	int	i;

// 	i = -1;
// 	row = 0;
// 	while (game->map.map[++i] != '\0')
// 	{
// 		if (game->map.map[i] == '\n')
// 			row++;
// 		if (game->map.map[i] != '\n' && \
// 			(game->map.cols) * (row) + (row - 1) == i)
// 			ft_error(game, 102);
// 	}
// }


/**
 * @brief Read file from given fd and allocated and assigned data as a string.
 * All \n and EOF is saved.
 * 
 * @param game 
 * @param fd 
 * @return char* 
 */
static char	*read_file(int fd)
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
 * @brief Initialize and validate parsed file data 
 * 
 * @param game 
 * @param map_address 
 * @return int * 
 */
int	init_data(t_game *game, char *map_address)
{
	if (!parse_cub_file(game, map_address))
		return (-1);
	if (!validate_game_data(game))
        return (-1);
	if (!init_graphics(game))
        return (-1);
	display_game(game);
	return (0);
}
