/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 18:43:00 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	validate_data_initialisation(t_test_data *data)
{
	if (!data->origin)
		return (print_fail("Test data ORIGIN is not exits"), 1);
	else if (!data->expect)
		return (print_fail("Test data EXPECT is not exits"), 1);
	if (!data->expect->north_texture_path
		|| !data->expect->south_texture_path
		|| !data->expect->west_texture_path
		|| !data->expect->east_texture_path
		|| !data->origin->north_texture_path
		|| !data->origin->south_texture_path
		|| !data->origin->west_texture_path
		|| !data->origin->east_texture_path)
		return (print_fail("Test textures path data is not exists"), 1);
	if (!data->expect->map_grid || !data->origin->map_grid)
		return (print_fail("Test map grid data is not exits"), 1);
	if (!data->expect->ceiling || !data->origin->ceiling)
		return (print_fail("Ceiling color data is not exits"), 1);
	if (!data->expect->floor || !data->origin->floor)
		return (print_fail("Floor color data is not exits"), 1);
	return (print_success("Data initialisation test is passed."), 0);
}

int	validate_colors(t_test_data *data)
{
	if (data->expect->ceiling->r != data->origin->ceiling->r)
		return (print_fail("Ceiling color<RED> validation failed."), 1);
	if (data->expect->ceiling->g != data->origin->ceiling->g)
		return (print_fail("Ceiling color<GREEN> validation failed."), 1);
	if (data->expect->ceiling->b != data->origin->ceiling->b)
		return (print_fail("Ceiling color<BLUE> validation failed."), 1);
	if (data->expect->floor->r != data->origin->floor->r)
		return (print_fail("Floor color<RED> validation failed."), 1);
	if (data->expect->floor->g != data->origin->floor->g)
		return (print_fail("Floor color<GREEN> validation failed."), 1);
	if (data->expect->floor->b != data->origin->floor->b)
		return (print_fail("Floor color<BLUE> validation failed."), 1);
	return (print_success("Color validation test is passed."), 0);
}

int	validate_textures_path(t_test_data *data)
{
	int	ret[4];

	ret[0] = ft_strcmp(data->expect->north_texture_path,
			data->origin->north_texture_path);
	ret[1] = ft_strcmp(data->expect->south_texture_path,
			data->origin->south_texture_path);
	ret[2] = ft_strcmp(data->expect->west_texture_path,
			data->origin->west_texture_path);
	ret[3] = ft_strcmp(data->expect->east_texture_path,
			data->origin->east_texture_path);
	if (ret[0])
		print_fail("--> Textures north path validation failed.");
	if (ret[1])
		print_fail("--> Textures south path validation failed.");
	if (ret[2])
		print_fail("--> Textures west path validation failed.");
	if (ret[3])
		print_fail("--> Textures east path validation failed.");
	if (ret[0] + ret[1] + ret[2] + ret[3])
		return (print_fail("Textures path validation failed."), 1);
	return (print_success("Textures path validation test is passed."), 0);
}

int	validate_map_grid(t_test_data *data)
{
	int		i;
	char	*str;

	i = -1;
	while (++i < data->height)
	{
		if (ft_strcmp(data->expect->map_grid[i], data->origin->map_grid[i]))
		{
			str = ft_strjoin("invalid Map grid at line ", ft_itoa(i));
			return (print_fail(str), 1);
		}
	}
	return (print_success("Map grid validation test is passed."), 0);
}

/**
 * @brief Each test compare is all data in origin equal expected
 * 
 * @param data->origin - parsed data
 * @param data->expect - what expected
 * @return int - 0 on success and 1 on error
 */
int	parser_test_map(t_test_data *data)
{
	int	ret;

	if (!data)
		return (print_fail("No test data provided"), 1);
	ret = validate_data_initialisation(data);
	if (ret)
		return (print_fail("Parser test failed."), 1);
	ret = validate_colors(data)
		+ validate_textures_path(data) + validate_map_grid(data);
	if (ret)
		return (print_fail("Parser test failed."), 1);
	return (print_success("Parser test passed."), 0);
}
