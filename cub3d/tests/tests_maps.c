/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/11 00:37:34 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_valid_parse_cub_file(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"));
	ft_printf(" --- Parser test 4 ---\n");
	if (parse_cub_file(game, "./tests/test_maps/map0.cub") == 0)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.pos.x, game->player.pos.y);
		return (s_free(game), print_success("Successfully parsed map0"));
	}
	else
		return (s_free(game), print_fail("Failed to parse map0"));
}

int	test_valid1_parse_cub_file(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	ft_memset(game, 0, sizeof(t_game));
	ft_printf(" --- Parser test 5 ---\n");
	if (parse_cub_file(game, "./tests/test_maps/map1.cub") == 0)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.pos.x, game->player.pos.y);
		return (s_free(game), print_success("Successfully parsed map1"));
	}
	else
		return (s_free(game), print_fail("Failed to parse map1"));
}

int	test_valid2_parse_cub_file(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	ft_memset(game, 0, sizeof(t_game));
	ft_printf(" --- Parser test 6 ---\n");
	if (parse_cub_file(game, "./tests/test_maps/map2.cub") == 0)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.pos.x, game->player.pos.y);
		return (s_free(game), print_success("Successfully parsed map2"));
	}
	else
		return (s_free(game), print_fail("Failed to parse map2"));
}
