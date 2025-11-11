/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:17:01 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/11 00:48:27 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Initialize and validate parsed file data
 *
 * @param game
 * @param map_address
 * @return int 1
 */
int	parse_cub_file(t_game *game, char *map_address)
{
	char	*file_data;
	int		fd;

	if (check_map_extension(map_address))
		return (print_error("Invalid map extension."));
	fd = open(map_address, O_RDONLY);
	if (fd == -1)
		return (print_error("File is invalid"));
	file_data = read_file(fd);
	close(fd);
	if (!parse_texture_elements(game, file_data))
		return (free(file_data), print_fail("Texture elements parser"));
	if (!parse_map_grid(game, file_data))
		return (free(file_data), print_fail("Map grid parser"));
	return (free(file_data), print_success("parse_cub_file - OK."));
}
