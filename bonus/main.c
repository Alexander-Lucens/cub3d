/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:43:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	init_data(game, av[1]);
	mlx_key_hook(game->graphics.win, key_press, game);
	mlx_hook(game->graphics.win, 17, 0, close_game, game);
	mlx_loop(game->graphics.mlx);
	close_game(game);
	return (0);
}
