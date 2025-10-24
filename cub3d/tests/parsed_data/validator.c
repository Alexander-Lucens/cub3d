/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 05:55:33 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

// Paste parser in this function and get validation
int run_as_validator(t_parsed_data *(*func)(char *))
{
	int				ret;
	t_parsed_data	*map0;
	t_parsed_data	*map1;
	t_parsed_data	*map2;

	ret = 0;
	map0 = func("../maps/map0.cub");
	map1 = func("../maps/map1.cub");
	map2 = func("../maps/map2.cub");

	ret += parser_test_map0(map0);
	ret += parser_test_map1(map1);
	ret += parser_test_map2(map2);

	if (ret != 0)
		return (1);
	return (0);
}
