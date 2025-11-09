/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_data_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:44:59 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/**
 * @brief Free test parsed data structure (for expect data from parsed_data_mapX)
 * 
 * @param data Test parsed data to free
 */
void	test_data_free(t_parsed_data *data)
{
	if (!data)
		return ;
	if (data->floor)
		c_free(data->floor);
	if (data->ceiling)
		c_free(data->ceiling);
	if (data->map_grid)
		free_split(data->map_grid);
	free(data);
}
