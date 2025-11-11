/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:45:28 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	assign_map(char **grid)
{
	grid[0] = ft_strdup("        1111111111111111111111111");
	grid[1] = ft_strdup("        1000000000110000000000001");
	grid[2] = ft_strdup("        1011000001110000000000001");
	grid[3] = ft_strdup("        1001000000000000000000001");
	grid[4] = ft_strdup("111111111011000001110000000000001");
	grid[5] = ft_strdup("1N0000000011000001110111111111111");
	grid[6] = ft_strdup("11110110001111011100000010001");
	grid[7] = ft_strdup("11110111111111011101010010001");
	grid[8] = ft_strdup("11000000110101011100000010001");
	grid[9] = ft_strdup("10000000000000000000000010001");
	grid[10] = ft_strdup("10000000000000001101010010001");
	grid[11] = ft_strdup("110000011101010111110111100111");
	grid[12] = ft_strdup("11110111 1110101 101111010001");
	grid[13] = ft_strdup("11111111 1111111 111111111111");
	grid[14] = NULL;
}

t_parsed_data	*parsed_data_map2(void)
{
	char			**grid;
	t_parsed_data	*data;

	grid = ft_calloc(sizeof(char *), MAP_2_HEIGHT + 1);
	if (!grid)
		return (NULL);
	data = ft_calloc(1, sizeof(t_parsed_data));
	if (!data)
		return (NULL);
	data->floor = init_rgb(220, 100, 0);
	data->ceiling = init_rgb(225, 30, 0);
	data->north_texture_path = "./textures/north_brick.xpm";
	data->south_texture_path = "./textures/red_brick.xpm";
	data->west_texture_path = "./textures/red_brick.xpm";
	data->east_texture_path = "./textures/red_brick.xpm";
	assign_map(grid);
	data->map_grid = grid;
	return (data);
}

int	parser_test_map2(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf(" --- Parser test 2 ---\n");
	expect = parsed_data_map2();
	data = init_test_struct(origin, expect, MAP_2_WIDTH, MAP_2_HEIGHT);
	ret = parser_test_map(data);
	test_data_free(expect);
	free(data);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}
