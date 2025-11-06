/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/06 17:18:53 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

t_parsed_data *parsed_data_map0(void)
{
	t_parsed_data *data = ft_calloc( 1, sizeof(t_parsed_data));
	if (!data)
		return (NULL);
	
	char **grid = ft_calloc(sizeof(char*), MAP_0_HEIGHT + 1);
	if (!grid)
		return (NULL);
	
	grid[0]		=	"111111111111111";
	grid[1]		=	"100000000000001";
    grid[2]		=	"100N00000000001";
    grid[3]		=	"100000000000001";
	grid[4]		=	"100001111000001";
	grid[5]		=	"100001001000001";
	grid[6]		=	"100001001000001";
	grid[7]		=	"100001111000001";
	grid[8]		=	"100000000000001";
	grid[9]		=	"100000000000001";
	grid[10]	=	"100000000000001";
	grid[11]	=	"111111111111111";
	grid[12]	=	NULL;	

	data->floor = init_rgb(220, 100, 0);
	data->ceiling  = init_rgb(225, 30, 0);
	data->north_texture_path = "./textures/north_brick.xpm";
	data->south_texture_path = "./textures/red_brick.xpm";
	data->west_texture_path = "./textures/red_brick.xpm";
	data->east_texture_path = "./textures/red_brick.xpm";
	data->map_grid = grid;

	return data;
}

t_parsed_data *parsed_data_map1(void)
{
	t_parsed_data *data = ft_calloc( 1, sizeof(t_parsed_data));
	if (!data)
		return (NULL);
	
	char **grid = ft_calloc(sizeof(char*), MAP_1_HEIGHT + 1);
	if (!grid)
		return (NULL);
	
	grid[0]		=	"11111111111";
	grid[1]		=	"10000000001";
    grid[2]		=	"10000000001";
    grid[3]		=	"1000000N001";
	grid[4]		=	"10000000001";
	grid[5]		=	"11111111111";
	grid[6]		=	NULL;	

	data->floor = init_rgb(220, 100, 0);
	data->ceiling  = init_rgb(225, 30, 0);
	data->north_texture_path = "./textures/north_brick.xpm";
	data->south_texture_path = "./textures/red_brick.xpm";
	data->west_texture_path = "./textures/red_brick.xpm";
	data->east_texture_path = "./textures/red_brick.xpm";
	data->map_grid = grid;

	return data;
}

t_parsed_data *parsed_data_map2(void)
{
	t_parsed_data *data = ft_calloc( 1, sizeof(t_parsed_data));
	if (!data)
		return (NULL);
	
	char **grid = ft_calloc(sizeof(char*), MAP_2_HEIGHT + 1);
	if (!grid)
		return (NULL);
	
	grid[0]		=	"        1111111111111111111111111";
	grid[1]		=	"        1000000000110000000000001";
    grid[2]		=	"        1011000001110000000000001";
    grid[3]		=	"        1001000000000000000000001";
	grid[4]		=	"111111111011000001110000000000001";
	grid[5]		=	"1N0000000011000001110111111111111";
	grid[6]		=	"11110110001111011100000010001";
	grid[7]		=	"11110111111111011101010010001";
	grid[8]		=	"11000000110101011100000010001";
	grid[9]		=	"10000000000000000000000010001";
	grid[10]	=	"10000000000000001101010010001";
	grid[11]	=	"110000011101010111110111100111";
	grid[12]	=	"11110111 1110101 101111010001";
	grid[13]	=	"11111111 1111111 111111111111";
	grid[14]	=	NULL;
	
	data->floor = init_rgb(220, 100, 0);
	data->ceiling  = init_rgb(225, 30, 0);
	data->north_texture_path = "./textures/north_brick.xpm";
	data->south_texture_path = "./textures/red_brick.xpm";
	data->west_texture_path = "./textures/red_brick.xpm";
	data->east_texture_path = "./textures/red_brick.xpm";
	data->map_grid = grid;

	return data;
}	