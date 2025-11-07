/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:17:01 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/07 17:43:43 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initialize and validate parsed file data
 *
 * @param game
 * @param map_address
 * @return int *
 */
t_game *parse_cub_file(t_game *game, char *map_address)
{
	char *file_data;
	int fd;

	if (check_map_extension(map_address))
		return (ft_error(game, "Invalid map extension."), NULL);
	fd = open(map_address, O_RDONLY);
	if (fd == -1)
		return (ft_error(game, "File is invalid"), NULL);
	file_data = read_file(fd);
	close(fd);
	// printf("File data read, length: %zu\n", ft_strlen(file_data));
	if (!parse_texture_elements(game, file_data))
		return (free(file_data), NULL);
	PRINT_SUCCESS("Parse texture passsed");
	if (!parse_map_grid(game, file_data))
		return (free(file_data), NULL);
	PRINT_SUCCESS("parse map grid passsed");
	printf("Map dimensions: %d x %d\n",
		   game->map.map_height, game->map.map_width);
	return (free(file_data), game);
}

// initialse struct
// error logic
// tests
// initialise map function