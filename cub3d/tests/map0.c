/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:40:11 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static void	assign_map(char **grid)
{
	grid[0] = ft_strdup("111111111111111");
	grid[1] = ft_strdup("100000000000001");
	grid[2] = ft_strdup("100N00000000001");
	grid[3] = ft_strdup("100000000000001");
	grid[4] = ft_strdup("100001111000001");
	grid[5] = ft_strdup("100001001000001");
	grid[6] = ft_strdup("100001001000001");
	grid[7] = ft_strdup("100001111000001");
	grid[8] = ft_strdup("100000000000001");
	grid[9] = ft_strdup("100000000000001");
	grid[10] = ft_strdup("100000000000001");
	grid[11] = ft_strdup("111111111111111");
	grid[12] = NULL;
}

t_parsed_data	*parsed_data_map0(void)
{
	char			**grid;
	t_parsed_data	*data;

	grid = ft_calloc(sizeof(char *), MAP_0_HEIGHT + 1);
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

int	parser_test_map0(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf("\n --- Parser test 0 ---\n");
	expect = parsed_data_map0();
	data = init_test_struct(origin, expect, MAP_0_WIDTH, MAP_0_HEIGHT);
	ret = parser_test_map(data);
	free(data);
	test_data_free(expect);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}
