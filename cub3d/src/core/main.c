/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:37 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		perror("Usage: ./cub3d <./maps/some_map.bmp>");
		return (0);
	}

	
	game = mock_data_create();

	/* Need to remake it to mlayer move
	game->player.delay = 0;
	mlx_hook(game->graphics.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->graphics.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->graphics.win, 17, 0, close_game, game);
	mlx_loop_hook(game->graphics.mlx, update, game);

	mlx_loop(game->graphics.mlx);
	// --------------------------------------------
	*/

	// close_game(game);
	return (0);
}




