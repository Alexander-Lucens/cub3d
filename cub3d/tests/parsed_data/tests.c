/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 21:43:20 by lkramer          ###   ########.fr       */
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
	ft_printf(" --- END OF TEST ---\n");
	return (ret);
}

int test_parse_texture_path()
{
    t_game game = {0};
    int result;
    
	ft_printf(" --- Parser test 3 ---\n");
    ft_printf("Testing parse_texture_path...\n");
    
    result = parse_texture_path(&game, "../textures/wn0.xpm", NORTH_TEXTURE);
    if (result && game.data.north_texture_path)
		return (PRINT_SUCCESS("North texture parsed successfully."), 0);
    else
        return (PRINT_FAIL("North texture parsing failed."), 1);
    
    result = parse_texture_path(&game, "./nonexistent.xpm", SOUTH_TEXTURE);
	ft_printf(" --- END OF TEST ---\n");
    if (!result)
        return (PRINT_SUCCESS("Correctly rejected file."), 0);
    else
        return (PRINT_FAIL("Should have rejected file."), 1);
}

int test_parse_color()
{
    t_game game = {0};
    int result;
    
	ft_printf(" --- Parser test 4 ---\n");
    ft_printf("Testing parse_color_path...\n");
    
    result = parse_color_path(&game, "255,128,0", FLOOR_COLOR);
    if (result && game.data.floor)
        return (PRINT_SUCCESS("Correctly passed colors."), 0);
    else
        return (PRINT_FAIL("Failed to parse color path."), 1);
    
    result = parse_color_path(&game, "300,128,0", CEILING_COLOR);
	ft_printf(" --- END OF TEST ---\n");
    if (!result)
        return (PRINT_SUCCESS("Correctly rejected path."), 0);
    else
        return (PRINT_FAIL("Should have rejected path, out of range."), 1);
}

int test_parse_cub_file()
{
    t_game *game;
    t_game *result;
    int test_failures = 0;
    
    ft_printf(" --- Parser test 5 ---\n");
    ft_printf("Testing parse_cub_file...\n");
    
    game = ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        PRINT_FAIL("Failed to allocate game");
        return (1);
    }
    
    result = parse_cub_file(game, "../maps/map0.cub");
    if (result)
        PRINT_SUCCESS("Successfully parsed map0.cub");
    else
    {
        PRINT_FAIL("Failed to parse map0.cub");
		ft_printf("Debug: parse_cub_file returned NULL\n");
        test_failures++;
    }
    if (result)
    {
        if (result->data.north_texture_path) free(result->data.north_texture_path);
        if (result->data.south_texture_path) free(result->data.south_texture_path);
        if (result->data.west_texture_path) free(result->data.west_texture_path);
        if (result->data.east_texture_path) free(result->data.east_texture_path);
        if (result->data.floor) free(result->data.floor);
        if (result->data.ceiling) free(result->data.ceiling);
        free(result);
    }

	game = ft_calloc(1, sizeof(t_game));
    result = parse_cub_file(game, "../maps/nonexistent.cub");
    if (!result)
        PRINT_SUCCESS("Correctly rejected non-existent file");
    else
	{
        PRINT_FAIL("Should have rejected non-existent file");
        test_failures++;
    }
    ft_printf(" --- END OF TEST ---\n");
    return (test_failures);
}