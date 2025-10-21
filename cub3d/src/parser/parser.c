/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:22:35 by lkramer           #+#    #+#             */
/*   Updated: 2025/10/21 19:22:20 by lkramer          ###   ########.fr       */
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
t_game *parse_cub_file(t_game *game, char *map_address)
{
	char *file_data;
	int fd;

	if (!check_map_extension(map_address))
		return (NULL);
	fd = open(map_address, O_RDONLY);
	if (fd == -1)
		ft_error(game, 100);
	file_data = read_file(fd);
	close(fd);
	if (!parse_elements(game, map_address))
	{
		free(file_data);
		return (0);
	}
	if(!parse_map_grid(game, map_address))
	{
		free(file_data);
		return (0);
	}
	free(file_data);
	return (1);
}


/**
 * @brief Parser for map elements
 * 
 * @return int * 
 */
int	parse_elements(t_game *game, char *content)
{
    char	**lines;
	int		i;
	
	lines = ft_split(content, '\n');
    i = 0;
    while (lines[i] && !is_map_start(lines[i]))
    {
		if (check_white_spaces_end_of_str(lines[i], &i))
			continue;
        if (ft_strncmp(lines[i][0][1], "NO ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, NORTH_TEXTURE);
        else if (ft_strncmp(lines[i], "SO ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, SOUTH_TEXTURE);
        else if (ft_strncmp(lines[i], "WE ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, WEST_TEXTURE);
        else if (ft_strncmp(lines[i], "EA ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, EAST_TEXTURE);
        else if (ft_strncmp(lines[i], "F ", 2) == 0)
            parse_color_path(game, lines[i] + 3, FLOOR_COLOR);
        else if (ft_strncmp(lines[i], "C ", 2) == 0)
            parse_color_path(game, lines[i] + 3, CEILING_COLOR);
        i++;
    }
    free_split(lines);
    return (validate_all_data(game));
}


