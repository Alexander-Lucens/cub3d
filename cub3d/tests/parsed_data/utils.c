/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 07:08:33 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"


int validate_data_initialisation(t_test_data *data)
{
	if (!data || !data->origin || !data->expect) {
		return (PRINT_FAIL("Test data is not exits"), 1);
	}
	if (!data->expect->north_texture_path || !data->expect->south_texture_path
        || !data->expect->west_texture_path || !data->expect->east_texture_path
        || !data->origin->north_texture_path || !data->origin->south_texture_path
        || !data->origin->west_texture_path || !data->origin->east_texture_path)
        return (PRINT_FAIL("Test textures path data is not exists"), 1);
	if (!data->expect->map_grid || !data->origin->map_grid)
        return (PRINT_FAIL("Test map grid data is not exits"), 1);
	if (!data->expect->ceiling || !data->origin->ceiling)
        return (PRINT_FAIL("Ceiling color data is not exits"), 1);
	if (!data->expect->floor || !data->origin->floor)
        return (PRINT_FAIL("Floor color data is not exits"), 1);
	return (PRINT_SUCCESS("Data initialisation test is passed."), 0);
}

int	validate_colors(t_test_data *data)
{
    int ret = 0;
    
    if (data->expect->ceiling->r != data->origin->ceiling->r) {
        PRINT_FAIL("Ceiling color<RED> validation failed.");
        ret++;
    }
    if (data->expect->ceiling->g != data->origin->ceiling->g) {
        PRINT_FAIL("Ceiling color<GREEN> validation failed.");
        ret++;
    }
    if (data->expect->ceiling->b != data->origin->ceiling->b) {
        PRINT_FAIL("Ceiling color<BLUE> validation failed.");
        ret++;
    }
    if (data->expect->floor->r != data->origin->floor->r) {
        PRINT_FAIL("Floor color<RED> validation failed.");
        ret++;
    }
    if (data->expect->floor->g != data->origin->floor->g) {
        PRINT_FAIL("Floor color<GREEN> validation failed.");
        ret++;
    }
    if (data->expect->floor->b != data->origin->floor->b) {
        PRINT_FAIL("Floor color<BLUE> validation failed.");
        ret++;
    }
	return (PRINT_SUCCESS("Color validation test is passed."), ret);
}

int	validate_textures_path(t_test_data *data)
{
	int ret[4];

	ret[0] = ft_strcmp(data->expect->north_texture_path, data->origin->north_texture_path);
	ret[1] = ft_strcmp(data->expect->south_texture_path, data->origin->south_texture_path);
	ret[2] = ft_strcmp(data->expect->west_texture_path, data->origin->west_texture_path);
	ret[3] = ft_strcmp(data->expect->east_texture_path, data->origin->east_texture_path);
	if (ret[0]) PRINT_FAIL(" --> Textures north path validation failed.");
	if (ret[1]) PRINT_FAIL(" --> Textures south path validation failed.");
	if (ret[2]) PRINT_FAIL(" --> Textures west path validation failed.");
	if (ret[3]) PRINT_FAIL(" --> Textures east path validation failed.");
	if (ret[0] + ret[1] + ret[2] + ret[3])
		return (PRINT_FAIL("Textures path validation failed."), 1);
	return (PRINT_SUCCESS("Textures path validation test is passed."), 0);
}

int validate_map_grid(t_test_data *data)
{
    int i;

    i = -1;
    while (++i < data->height)
    {
        if (ft_strcmp(data->expect->map_grid[i], data->origin->map_grid[i]))
            return (PRINT_FAIL("Map grid validation test failed."), 1);
    }
    return (PRINT_SUCCESS("Map grid validation test is passed."), 0);
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
    int ret;

    if (!data) {
        return (PRINT_FAIL("No test data provided"), 1);
    }
    ret = validate_data_initialisation(data);
    if (ret) {
        return (PRINT_FAIL("Parser test failed."), 1);
    }
    ret = validate_colors(data) + validate_textures_path(data) + validate_map_grid(data);
    if (ret)
        return (PRINT_FAIL("Parser test failed."), 1);
    return (PRINT_SUCCESS("Parser test passed."), 0);
}
