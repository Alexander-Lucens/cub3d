/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/10 23:46:00 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

// Paste parser in this function and get validation
int	run_as_validator(t_parsed_data *(*func)(char *))
{
	int				ret;
	t_parsed_data	*map0;
	t_parsed_data	*map1;
	t_parsed_data	*map2;

	ret = 0;
	map0 = func("../textures/test_maps/map0.cub");
	map1 = func("../textures/test_maps/map1.cub");
	map2 = func("../textures/test_maps/map2.cub");
	ret += parser_test_map0(map0);
	ret += parser_test_map1(map1);
	ret += parser_test_map2(map2);
	if (ret != 0)
		return (1);
	return (0);
}

// Paste parser in this function and get validation
int	run_as_validator_game(int (*func)(t_game *, char *))
{
	int		ret;
	t_game	*game[3];

	game[0] = ft_calloc(1, sizeof(t_game));
	if (!game[0])
		return (print_fail("Failed to allocate memory"), 1);
	game[1] = ft_calloc(1, sizeof(t_game));
	if (!game[1])
		return (print_fail("Failed to allocate memory"), 1);
	game[2] = ft_calloc(1, sizeof(t_game));
	if (!game[2])
		return (print_fail("Failed to allocate memory"), 1);
	ret = 0;
	if (func(game[0], "./textures/test_maps/map0.cub")
		|| func(game[1], "./textures/test_maps/map1.cub")
		|| func(game[2], "./textures/test_maps/map2.cub"))
		print_fail("validator: fail run parser function.");
	else
		ret += parser_test_map0(&game[0]->data)
		+ parser_test_map1(&game[1]->data)
		+ parser_test_map2(&game[2]->data);
	s_free(game[0]);
	s_free(game[1]);
	s_free(game[2]);
	if (ret)
		return (print_fail("validator: faild."));
	return (print_success("validator - OK."));
}
