/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 04:45:41 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tests.h"

// int	main(int ac, char **av)
// {
// 	t_game	*game;

// 	if (ac != 2)
// 	{
// 		perror("Usage: ./parser_tests <Number: 0, 1, 2 - for maps in maps/>");
// 		return (1);
// 	}
// 	int num = ft_atoi(av[1]);
// 	if (!num || num < 0 || num > 2) {
// 		perror("Invalid Number, there is no test data for it!");
// 		return (1);
// 	}
	
// 	game = mock_dataset_create(num);
// 	game->player.delay = 0;
	
// 	mlx_hook(game->graphics.win, 2, 1L << 0, key_press, game);
// 	mlx_hook(game->graphics.win, 3, 1L << 1, key_release, game);
// 	mlx_hook(game->graphics.win, 17, 0, close_game, game);

// 	mlx_loop_hook(game->graphics.mlx, update, game);

// 	mlx_loop(game->graphics.mlx);
// 	// --------------------------------------------
	
// 	close_game(game);
// 	return (0);
// }

