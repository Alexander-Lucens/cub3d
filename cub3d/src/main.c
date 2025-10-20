/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/20 15:26:19 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		perror("Usage: ./cub3d <./maps/some_map.bmp>");
		return (0);
	}

	
	// There will be all Parser LOGIC
	// game = parser(av[1]);
	
	
	/*
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
	*/
	
	game = mock_data_create();
	
	mlx_hook(game->graphics.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->graphics.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->graphics.win, 17, 0, close_game, game);
	mlx_loop_hook(game->graphics.mlx, update, game);

	mlx_loop(game->graphics.mlx);
	// --------------------------------------------
	
	close_game(game);
	return (0);
}

char **create_mock_map(void) {
	char **map = ft_calloc(sizeof(char*), 15);
	if (!map)
		return exit(1);
	
	map[0] = "        1111111111111111111111111";
	map[1] = "        1000000000110000000000001";
    map[2] = "        1011000001110000000000001";
    map[3] = "        1001000000000000000000001";
	map[1] = "111111111011000001110000000000001";
	map[1] = "100000000011000001110111111111111";
	map[1] = "11110110001111011100000010001";
	map[1] = "11110111111111011101010010001
	map[1] = "11000000110101011100000010001
	map[1] = "10000000000000000000000010001
	map[1] = "10000000000000001101010010001
	map[1] = "11000001110101011111011110N0111
	map[1] = "11110111 1110101 101111010001
	map[1] = "11111111 1111111 111111111111";
		

	}
}

t_game* mock_data_create(void) {
	game = ft_calloc(sizeof(t_game), sizeof(t_game));
	if (!game)
		return exit(1);
	
}	



