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

	game->player.delay = 0;
	
	mlx_hook(game->graphics.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->graphics.win, 3, 1L << 1, key_release, game);
	mlx_hook(game->graphics.win, 17, 0, close_game, game);
	mlx_loop_hook(game->graphics.mlx, update, game);

	mlx_loop(game->graphics.mlx);
	// --------------------------------------------
	
	close_game(game);
	return (0);
}

t_map *create_mock_map(void) {
	t_map *map = ft_calloc(sizeof(t_map), sizeof(t_map));
	if (!map)
		return exit(1);
	
	char **grid = ft_calloc(sizeof(char*), 14);
	if (!grid)
		return exit(1);
	
	grid[0]		=	"        1111111111111111111111111";
	grid[1]		=	"        1000000000110000000000001";
    grid[2]		=	"        1011000001110000000000001";
    grid[3]		=	"        1001000000000000000000001";
	grid[4]		=	"111111111011000001110000000000001";
	grid[5]		=	"100000000011000001110111111111111";
	grid[6]		=	"11110110001111011100000010001    ";
	grid[7]		=	"11110111111111011101010010001    ";
	grid[8]		=	"11000000110101011100000010001    ";
	grid[9]		=	"10000000000000000000000010001    ";
	grid[10]	=	"10000000000000001101010010001    ";
	grid[11]	=	"11000001110101011111011110N0111  ";
	grid[12]	=	"11110111 1110101 101111010001    ";
	grid[13]	=	"11111111 1111111 111111111111    ";
	grid[14]	=	NULL;	

	map->grid = grid;
	map->map_width = 34;
	map->map_height = 14;

	return map;
}

t_game* mock_data_create(void) {
	t_game *game = ft_calloc(sizeof(t_game), sizeof(t_game));
	if (!game)
		return exit(1);
	game->map = create_mock_map();
	// FINISH IT
}	



