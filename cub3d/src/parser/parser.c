/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:17:01 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/04 11:44:13 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Initialize and validate parsed file data 
 * 
 * @param game 
 * @param map_address 
 * @return int * 
 */
t_game	*parse_cub_file(t_game *game, char *map_address)
{
	char	*file_data;
	int		fd;

	check_map_extension(map_address);
	fd = open(map_address, O_RDONLY);
	if (fd == -1)
		return (printf("Error file descriptor"), NULL);
		// ft_error(game, 100);
	file_data = read_file(fd);
	close(fd);
	// printf("File data read, length: %zu\n", ft_strlen(file_data));
	if (!parse_texture_elements(game, file_data))
		return (free(file_data), NULL);
	PRINT_SUCCESS("Parse texture passsed");
	if (!parse_map_grid(game, file_data))
		return (free(file_data), game);
	PRINT_SUCCESS("parse map grid passsed");
	printf("Map dimensions: %d x %d\n",
		game->map.map_height, game->map.map_width);
	return (/* free(file_data),*/ game);
}
