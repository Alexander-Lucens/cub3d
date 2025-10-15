/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/14 17:19:00 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		perror("Usage: ./so_long <./maps/some_map.bmp>");
		return (0);
	}
	game = ft_calloc(sizeof(t_game), sizeof(t_game));
	if (!game)
		return (0);
	game->graphics.mlx = mlx_init();
	if (!game->graphics.mlx)
		ft_error(game, 101);
	game->player_direction.x = 1;
	game->player_direction.y = 0;
	init_data(game, av[1]);

	ft_bzero(&game->controls, sizeof(t_controls));

	// Get key press and move in cub3d make it work with float numbers
	game->move_cooldown = 0;
	mlx_hook(game->graphics.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->graphics.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->graphics.win, 17, 0, close_game, game);
	mlx_loop_hook(game->graphics.mlx, update, game);

	mlx_loop(game->graphics.mlx);
	// --------------------------------------------
	
	close_game(game);
	return (0);
}
