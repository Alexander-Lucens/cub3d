/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:22:35 by lkramer           #+#    #+#             */
/*   Updated: 2025/10/31 12:20:09 by akuzmin          ###   ########.fr       */
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
	char *file_data;
	int fd;

	check_map_extension(map_address);
	fd = open(map_address, O_RDONLY);
	if (fd == -1)
		return (printf("Error file descriptor"), NULL);
	// ft_error(game, 100);
	file_data = read_file(fd);
	close(fd);
	if (!parse_elements(game, file_data))
		return (free(file_data), NULL);
	/* if(!parse_map_grid(game, file_data))
		return (free(file_data), 0); */
	return (free(file_data), game);
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
    while (lines[i])
    {
		if (check_white_spaces_end_of_str(lines, &i))
			continue;
        if (ft_strncmp(lines[i], "NO ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, NORTH_TEXTURE);
        else if (ft_strncmp(lines[i], "SO ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, SOUTH_TEXTURE);
        else if (ft_strncmp(lines[i], "WE ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, WEST_TEXTURE);
        else if (ft_strncmp(lines[i], "EA ", 3) == 0)
            parse_texture_path(game, lines[i] + 3, EAST_TEXTURE);
        else if (ft_strncmp(lines[i], "F ", 2) == 0)
            parse_color_path(game, lines[i] + 2, FLOOR_COLOR);
        else if (ft_strncmp(lines[i], "C ", 2) == 0)
            parse_color_path(game, lines[i] + 2, CEILING_COLOR);
        i++;
    }
    return (printf("TEST\n"), free_split(lines), validate_all_data(game));
}


/**
 * @brief Parser for the texture path
 * Checks for whitespaces, adds file extension, parses 
 * strings to parse_data struct
 * @return int * 
 */
int parse_texture_path(t_game *game, char *path_str, char *texture_type)
{
    char *trimmed_path;
	char *full_path;
    
    trimmed_path = ft_strtrim(path_str, " \t\n");
    if (!trimmed_path)
		return (0);
	if (!ft_strnstr(trimmed_path, ".xpm", ft_strlen(trimmed_path)))
    {
        full_path = ft_strjoin(trimmed_path, ".xpm");
        free(trimmed_path);
    }
    else
		full_path = trimmed_path;
	if (access(full_path, F_OK) != 0)
		return (free(full_path), 0);
	if (ft_strcmp(texture_type, NORTH_TEXTURE) == 0)
        game->data.north_texture_path = ft_strdup(full_path);
	else if (ft_strcmp(texture_type, SOUTH_TEXTURE) == 0)
		game->data.south_texture_path  = ft_strdup(full_path);
	else if (ft_strcmp(texture_type, WEST_TEXTURE) == 0)
        game->data.west_texture_path = ft_strdup(full_path);
	else if (ft_strcmp(texture_type, EAST_TEXTURE) == 0)
		game->data.east_texture_path  = ft_strdup(full_path);
	return (free(full_path), 1);
}

/**
 * @brief Parser for the color path
 * Checks for whitespaces, parses strings to 
 * parse_data struct
 * @return int * 
 */
int	parse_color_path(t_game *game, char *color_str, char *color_type)
{
    char	**rgb_parts;
	char	*trimmed;
    int		r;
	int		g; 
	int		b;
	t_rgb	*color;
    
    trimmed = ft_strtrim(color_str, " \t\n");
    rgb_parts = ft_split(trimmed, ',');
    if (!rgb_parts || !rgb_parts[0] || !rgb_parts[1] || !rgb_parts[2] || rgb_parts[3])
  		return (free_split(rgb_parts), free(trimmed), 0);
    r = ft_atoi(rgb_parts[0]);
    g = ft_atoi(rgb_parts[1]);
    b = ft_atoi(rgb_parts[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (free_split(rgb_parts), free(trimmed), 0);
	color = create_rgb_color(r, g, b);
    if (!color)
		return (free_split(rgb_parts), free(trimmed), 0);
    if (ft_strcmp(color_type, FLOOR_COLOR) == 0)
		game->data.floor  = color;
    else if (ft_strcmp(color_type, CEILING_COLOR) == 0)
		game->data.ceiling = color;
    return (free_split(rgb_parts), free(trimmed), 1);
}

/**
 * @brief Allocates memory for color variables
 * and stores values in parse_data struct
 * @return int * 
 */
t_rgb	create_rgb_color(int r, int g, int b)
{
	t_rgb	color;

    if ((r < 0 || r > 255) ||
        (g < 0 || g > 255) ||
        (b < 0 || r > 255))
        return (NULL);
    color.r = r;
    color.g = g;
    color.b = b;
	return (color);
}


/**
 * @brief Validates all struct values exist
 * 
 * @return int * 
 */
int	validate_all_data(t_game *game)
{
    if (!game->data.north_texture_path || 
        !game->data.south_texture_path ||
        !game->data.east_texture_path || 
        !game->data.west_texture_path)
        return (0);
    if (!game->data.floor || !game->data.ceiling)
        return (0);
    return (1);
} 