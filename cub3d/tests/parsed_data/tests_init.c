/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:14 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/**
 * @brief Get origin data and data for comparison and pack it in one structure
 * 
 * @param origin 
 * @param expect 
 * @return t_test_data* 
 */
t_test_data	*init_test_struct(t_parsed_data *origin,
	t_parsed_data *expect, int width, int height)
{
	t_test_data	*data;

	data = ft_calloc(1, sizeof(t_test_data));
	if (!data)
		return (PRINT_FAIL("calloc fails in __init_test_struct__"), NULL);
	data->expect = expect;
	data->origin = origin;
	data->height = height;
	data->width = width;
	return (data);
}

t_rgb	*init_rgb(int r, int g, int b)
{
	t_rgb	*color;

	color = ft_calloc(1, sizeof(t_rgb));
	if (!color)
		return (PRINT_FAIL("calloc fails in __init_rgb__"), NULL);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}
