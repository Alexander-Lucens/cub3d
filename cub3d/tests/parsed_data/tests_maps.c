/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 18:47:34 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_valid_parse_cub_file(void)
{
	t_game	*game;
	t_game	*result;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	ft_printf(" --- Parser test 4 ---\n");
	result = parse_cub_file(game, "./textures/test_maps/map0.cub");
	if (result && game->map.matrix && game->data.north_texture_path)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.pos.x, game->player.pos.y);
		return (s_free(game), print_success("Successfully parsed map0"), 0);
	}
	else
		return (s_free(game), print_fail("Failed to parse map0"), 1);
}

int	test_valid1_parse_cub_file(void)
{
	t_game	*game;
	t_game	*result;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	ft_memset(game, 0, sizeof(t_game));
	ft_printf(" --- Parser test 5 ---\n");
	result = parse_cub_file(game, "./textures/test_maps/map1.cub");
	if (result && game->map.matrix && game->data.north_texture_path)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.pos.x, game->player.pos.y);
		return (s_free(game), print_success("Successfully parsed map1"), 0);
	}
	else
		return (s_free(game), print_fail("Failed to parse map1"), 1);
}

int	test_valid2_parse_cub_file(void)
{
	t_game	*game;
	t_game	*result;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	ft_memset(game, 0, sizeof(t_game));
	ft_printf(" --- Parser test 6 ---\n");
	result = parse_cub_file(game, "./textures/test_maps/map2.cub");
	if (result && game->map.matrix && game->data.north_texture_path)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.pos.x, game->player.pos.y);
		return (s_free(game), print_success("Successfully parsed map2"), 0);
	}
	else
		return (s_free(game), print_fail("Failed to parse map2"), 1);
}
