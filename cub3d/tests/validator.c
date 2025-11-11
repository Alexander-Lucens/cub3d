/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/11 01:53:33 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static int	free_game_pointers(t_game **game)
{
	if (!game)
		return (1);
	if (game[0])
		s_free(game[0]);
	if (game[1])
		s_free(game[1]);
	if (game[2])
		s_free(game[2]);
	return (free(game), 1);
}

int	run_as_validator_game(void)
{
	int		ret;
	t_game	**game;

	game = ft_calloc(3, sizeof(t_game *));
	if (!game)
		return (print_fail("validator: allocation failed."));
	game[0] = ft_calloc(1, sizeof(t_game));
	game[1] = ft_calloc(1, sizeof(t_game));
	game[2] = ft_calloc(1, sizeof(t_game));
	if (!game[0] || !game[1] || !game[2])
		return (free_game_pointers(game),
			print_fail("validator: struct allocation failed."));
	ret = parse_cub_file(game[0], "./tests/test_maps/map0.cub");
	ret += parse_cub_file(game[1], "./tests/test_maps/map1.cub");
	ret += parse_cub_file(game[2], "./tests/test_maps/map2.cub");
	if (ret == 0)
		ret += parser_test_map0(&(game[0]->data))
			+ parser_test_map1(&(game[1]->data))
			+ parser_test_map2(&(game[2]->data));
	else
		print_fail("validator: parsing failed, skipping data tests.");
	free_game_pointers(game);
	if (ret)
		return (print_fail("validator: test failed."));
	return (print_success("validator - OK."));
}
