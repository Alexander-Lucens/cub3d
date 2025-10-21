/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moks_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mockdata.h"

t_map *mock_create_map0(void) {
	t_map *map = ft_calloc(sizeof(t_map), sizeof(t_map));
	if (!map)
		return exit(1);
	
	char **grid = ft_calloc(sizeof(char*), MAP_0_HEIGHT);
	if (!grid)
		return exit(1);
	
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

	map->grid = grid;
	map->map_width = MAP_0_WIDTH;
	map->map_height = MAP_0_HEIGHT;

	return map;
}

t_map *mock_create_map2(void) {
	t_map *map = ft_calloc(sizeof(t_map), sizeof(t_map));
	if (!map)
		return exit(1);
	
	char **grid = ft_calloc(sizeof(char*), MAP_1_HEIGHT);
	if (!grid)
		return exit(1);
	
	grid[0]		=	"11111111111";
	grid[1]		=	"10000000001";
    grid[2]		=	"10000000001";
    grid[3]		=	"1000000S001";
	grid[4]		=	"10000000001";
	grid[5]		=	"11111111111";
	grid[6]		=	NULL;	

	map->grid = grid;
	map->map_width = MAP_1_WIDTH;
	map->map_height = MAP_1_HEIGHT;

	return map;
}

t_map *mock_create_map2(void) {
	t_map *map = ft_calloc(sizeof(t_map), sizeof(t_map));
	if (!map)
		return exit(1);
	
	char **grid = ft_calloc(sizeof(char*), MAP_2_HEIGHT);
	if (!grid)
		return exit(1);
	
	grid[0]		=	"        1111111111111111111111111";
	grid[1]		=	"        1000000000110000000000001";
    grid[2]		=	"        1011000001110000000000001";
    grid[3]		=	"        1001000000000000000000001";
	grid[4]		=	"111111111011000001110000000000001";
	grid[5]		=	"100000000011000001110111111111111";
	grid[6]		=	"11110110001111011100000010001    ";
	grid[7]		=	"11110111111111011101010010001    ";
	grid[8]		=	"11000000110101011100000010001    ";
	grid[9]		=	"10000000000000000000000010001    ";
	grid[10]	=	"10000000000000001101010010001    ";
	grid[11]	=	"11000001110101011111011110N0111  ";
	grid[12]	=	"11110111 1110101 101111010001    ";
	grid[13]	=	"11111111 1111111 111111111111    ";
	grid[14]	=	NULL;	

	map->grid = grid;
	map->map_width = MAP_2_WIDTH;
	map->map_height = MAP_2_HEIGHT;

	return map;
}	

