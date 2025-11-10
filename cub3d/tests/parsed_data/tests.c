/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/10 22:49:05 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	test_valid_parse_texture_path(void)
{
	t_game	*game;
	int		result;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	ft_printf(" --- Parser test 3 ---\n");
	result = parse_texture_path(game,
			"./textures/north_brick.xpm", NORTH_TEXTURE);
	if (result && game->data.north_texture_path)
		return (s_free(game),
			print_success("North texture parsed successfully."));
	else
		return (s_free(game), print_fail("North texture parsing failed."));
}

int	test_invalid_parse_texture_path(void)
{
	t_game	*game;
	int		result;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	result = parse_texture_path(game,
			"./nonexistent.xpm", SOUTH_TEXTURE);
	if (!result)
		return (s_free(game), print_success("Correctly rejected file."));
	else
		return (s_free(game), print_fail("Should have rejected file."));
}

int	test_valid_parse_color(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	if (parse_color_path(game, "255, 128, 0", FLOOR_COLOR) == 0)
		return (s_free(game), print_success("Correctly passed colors."));
	else
		return (s_free(game), print_fail("Failed to parse color path."));
}

int	test_invalid_parse_color(void)
{
	t_game	*game;
	int		result;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_fail("Failed to allocate memory"), 1);
	result = parse_color_path(game, "300,128,0", CEILING_COLOR);
	if (!result)
		return (s_free(game), print_success("Correctly rejected path."));
	else
		return (s_free(game),
			print_fail("Should have rejected path, out of range."));
}
