/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:22:35 by lkramer           #+#    #+#             */
/*   Updated: 2025/11/04 17:04:59 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Parser for the texture path
 * Checks for whitespaces, adds file extension, parses 
 * strings to parse_data struct
 * @return int * 
 */
int	parse_texture_path(t_game *game, char *path_str, char *texture_type)
{
	char	*trimmed_path;
	char	*full_path;

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
		game->data.south_texture_path = ft_strdup(full_path);
	else if (ft_strcmp(texture_type, WEST_TEXTURE) == 0)
		game->data.west_texture_path = ft_strdup(full_path);
	else if (ft_strcmp(texture_type, EAST_TEXTURE) == 0)
		game->data.east_texture_path = ft_strdup(full_path);
	return (free(full_path), 1);
}

static int	parse_rgb_values(char *color_str, int rgb[3])
{
	char	**rgb_values;
	char	*trimmed;

	trimmed = ft_strtrim(color_str, " \t\n");
	if (!trimmed)
		return (0);
	rgb_values = ft_split(trimmed, ',');
	if (!rgb_values || !rgb_values[0] || !rgb_values[1]
		|| !rgb_values[2] || rgb_values[3])
		return (free_split(rgb_values), free(trimmed), 0);
	rgb[0] = ft_atoi(rgb_values[0]);
	rgb[1] = ft_atoi(rgb_values[1]);
	rgb[2] = ft_atoi(rgb_values[2]);
	return (free_split(rgb_values), free(trimmed), 1);
}

/**
 * @brief Allocates memory for color variables
 * and stores values in parse_data struct
 * @return int * 
 */
static t_rgb	*create_rgb_color(int r, int g, int b)
{
	t_rgb	*color;

	color = malloc(sizeof(t_rgb));
	if (!color)
		return (NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

/**
 * @brief Parser for the color path
 * Checks for whitespaces, parses strings to 
 * parse_data struct
 * @return int * 
 */
int	parse_color_path(t_game *game, char *color_str, char *color_type)
{
	int		rgb[3];
	t_rgb	*color;

	if (!parse_rgb_values(color_str, rgb))
		return (0);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
		|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (0);
	color = create_rgb_color(rgb[0], rgb[1], rgb[2]);
	if (!color)
		return (free(color), 0);
	if (ft_strcmp(color_type, FLOOR_COLOR) == 0)
		game->data.floor = color;
	else if (ft_strcmp(color_type, CEILING_COLOR) == 0)
		game->data.ceiling = color;
	return (1);
}

/**
 * @brief Parser for map elements
 * 
 * @return int * 
 */
int	parse_texture_elements(t_game *game, char *content)
{
	char	**lines;
	int		i;

	lines = ft_split(content, '\n');
	i = 0;
	while (lines[i])
	{
		if (check_white_spaces_end_of_str(lines, &i))
			continue ;
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
	return (free_split(lines), validate_all_data(game));
}
