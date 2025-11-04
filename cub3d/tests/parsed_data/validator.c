/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/03 14:31:26 by akuzmin          ###   ########.fr       */
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

// Paste parser in this function and get validation
int run_as_validator_game(t_game *(*func)(t_game *, char *))
{
	int		ret;

	t_game *game0 = malloc(sizeof(t_game));
	if (!game0)
		return (PRINT_FAIL("Failed to allocate memory"));
	ft_memset(game0, 0, sizeof(t_game));
	t_game *game1 = malloc(sizeof(t_game));
	if (!game1)
		return (PRINT_FAIL("Failed to allocate memory"));
	ft_memset(game1, 0, sizeof(t_game));
	t_game *game2 = malloc(sizeof(t_game));
	if (!game2)
		return (PRINT_FAIL("Failed to allocate memory"));
	ft_memset(game2, 0, sizeof(t_game));

	ret = 0;
	game0 = func(game0, "../textures/map0.cub");
	game1 = func(game1, "../textures/map1.cub");
	game2 = func(game2, "../textures/map2.cub");

	ret += parser_test_map0(&game0->data);
	ret += parser_test_map1(&game1->data);
	ret += parser_test_map2(&game2->data);

	if (ret != 0)
		return (1);
	return (0);
}
