/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 20:25:28 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (print_error("Usage: ./cub3d <./maps/some_map.cub>"), 1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (print_error("Memory allocation error."), 1);
	if (init_data(game, av[1]))
		return (s_free(game), 1);
	game->player.last_update_time = get_time_in_us();
	mlx_hook(game->graphics.window, 2, 1L << 0, key_press, game);
	mlx_hook(game->graphics.window, 3, 1L << 1, key_release, game);
	mlx_hook(game->graphics.window, 17, 0, close_game, game);
	mlx_loop_hook(game->graphics.mlx, update, game);
	mlx_loop(game->graphics.mlx);
	return (s_free(game), print_success("Program finished as expected!"), 0);
}
