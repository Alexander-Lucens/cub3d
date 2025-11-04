/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:20:48 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	parser_test_map0(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf("\n --- Parser test 0 ---\n");
	expect = parsed_data_map0();
	data = init_test_struct(origin, expect, MAP_0_WIDTH, MAP_0_HEIGHT);
	ret = parser_test_map(data);
	free(data);
	test_data_free(expect);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}

int	parser_test_map1(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf(" --- Parser test 1 ---\n");
	expect = parsed_data_map1();
	data = init_test_struct(origin, expect, MAP_1_WIDTH, MAP_1_HEIGHT);
	ret = parser_test_map(data);
	free(data);
	test_data_free(expect);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}

int	parser_test_map2(t_parsed_data *origin)
{
	int				ret;
	t_test_data		*data;
	t_parsed_data	*expect;

	ft_printf(" --- Parser test 2 ---\n");
	expect = parsed_data_map2();
	data = init_test_struct(origin, expect, MAP_2_WIDTH, MAP_2_HEIGHT);
	ret = parser_test_map(data);
	free(data);
	test_data_free(expect);
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}

int	test_valid_parse_texture_path(void)
{
	t_game	game = {0};
	int		result;

	ft_printf(" --- Parser test 3 ---\n");
	result = parse_texture_path(&game, "./textures/wn0.xpm", NORTH_TEXTURE);
	if (result && game.data.north_texture_path)
	{
		if (game.data.north_texture_path)
			free(game.data.north_texture_path);
		return (PRINT_SUCCESS("North texture parsed successfully."), 0);
	}
	else
	{
		if (game.data.north_texture_path)
			free(game.data.north_texture_path);
		return (PRINT_FAIL("North texture parsing failed."), 1);
	}
}

int	test_invalid_parse_texture_path(void)
{
	t_game	game = {0};
	int		result;

	result = parse_texture_path(&game, "./nonexistent.xpm", SOUTH_TEXTURE);
	if (!result)
	{
		if (game.data.north_texture_path)
			free(game.data.north_texture_path);
		return (PRINT_SUCCESS("Correctly rejected file."), 0);
	}
	else
	{
		if (game.data.north_texture_path)
			free(game.data.north_texture_path);
		return (PRINT_FAIL("Should have rejected file."), 1);
	}
}

int	test_valid_parse_color(void)
{
	t_game 		game = {0};
	int 		result;

	result = parse_color_path(&game, "255,128,0", FLOOR_COLOR);
	if (result && game.data.floor)
	{
		if (game.data.floor)
			c_free(game.data.floor);
		return (PRINT_SUCCESS("Correctly passed colors."), 0);
	}
	else
	{
		if (game.data.floor)
			c_free(game.data.floor);
		return (PRINT_FAIL("Failed to parse color path."), 1);
	}
}

int	test_invalid_parse_color(void)
{
	t_game 		game = {0};
	int 		result;

	result = parse_color_path(&game, "300,128,0", CEILING_COLOR);
	if (!result)
	{
		if (game.data.floor)
			c_free(game.data.floor);
		return (PRINT_SUCCESS("Correctly rejected path."), 0);
	}
	else
	{
		if (game.data.floor)
			c_free(game.data.floor);
		return (PRINT_FAIL("Should have rejected path, out of range."), 1);
	}
}

int	test_valid_parse_cub_file(void)
{
	t_game	*game;
	t_game	*result;

	game = malloc(sizeof(t_game));
	if (!game)
		return (PRINT_FAIL("Failed to allocate memory"));
	ft_memset(game, 0, sizeof(t_game));

	ft_printf(" --- Parser test 4 ---\n");
	result = parse_cub_file(game, "./textures/test_maps/map0.cub");
	if (result && game->map.matrix && game->data.north_texture_path)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.position.x, game->player.position.y);
		s_free(game);
		return (PRINT_SUCCESS("Successfully parsed map0file"), 0);
	}
	else
	{
		s_free(game);
		return (PRINT_FAIL("Failed to parse map0 file"), 1);
	}
}

int	test_valid1_parse_cub_file(void)
{
	t_game	*game;
	t_game	*result;

	game = malloc(sizeof(t_game));
	if (!game)
		return (PRINT_FAIL("Failed to allocate memory"));
	ft_memset(game, 0, sizeof(t_game));

	ft_printf(" --- Parser test 5 ---\n");
	result = parse_cub_file(game, "./textures/test_maps/map1.cub");
	if (result && game->map.matrix && game->data.north_texture_path)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.position.x, game->player.position.y);
		s_free(game);
		return (PRINT_SUCCESS("Successfully parsed map1 file"), 0);
	}
	else
	{
		s_free(game);
		return (PRINT_FAIL("Failed to parse map1 file"), 1);
	}
}

int	test_valid2_parse_cub_file(void)
{
	t_game	*game;
	t_game	*result;

	game = malloc(sizeof(t_game));
	if (!game)
		return (PRINT_FAIL("Failed to allocate memory"));
	ft_memset(game, 0, sizeof(t_game));

	ft_printf(" --- Parser test 6 ---\n");
	result = parse_cub_file(game, "./textures/test_maps/map2.cub");
	if (result && game->map.matrix && game->data.north_texture_path)
	{
		printf("Player at: (%.1f, %.1f)\n",
			game->player.position.x, game->player.position.y);
		s_free(game);
		return (PRINT_SUCCESS("Successfully parsed map2 file"), 0);
	}
	else
	{
		s_free(game);
		return (PRINT_FAIL("Failed to parse map2 file"), 1);
	}
}

