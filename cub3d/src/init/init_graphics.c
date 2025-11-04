/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/03 09:43:29 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ALL exit(EXIT_FAILURE) MUST BE REPLACES TO --> cleanup function

int create_int_rgb(const t_rgb *color);

static int init_window(t_game *game) 
{
	int	width;
	int	height;

	mlx_get_screen_size(game->graphics.mlx, &width, &height);
	if (!width || !height) {
		width = DEF_WIN_WIDTH;
		height = DEF_WIN_HEIGHT;
	}
	game->graphics.win = mlx_new_window(game->graphics.mlx, width, height, "cub3d");
	if (!game->graphics.win) {
		return (EXIT_FAILURE);
	}
	return (0);
}

static int	load_texture(t_graphics *gfx, t_image *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(gfx->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (perror("Error: failed to load texture: "), 1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
        return (perror("Error: mlx_get_data_addr failed"), 1);
	return (0);
}

// Image size predefined and set in defines.h as 10
static void	init_images(t_game *game)
{
	if (load_texture(game->graphics, game->graphics.north, game->data.north_texture_path)
		|| load_texture(game->graphics, game->graphics.south, game->data.south_texture_path)
		|| load_texture(game->graphics, game->graphics.east, game->data.east_texture_path)
		|| load_texture(game->graphics, game->graphics.west, game->data.west_texture_path) )
	{
		game->is_error = EXIT_FAILURE;
		return ;
	}
	game->graphics.floor_color = create_int_rgb(game->data.floor);
	game->graphics.ceiling_color = create_int_rgb(game->data.ceiling);
	if (game->graphics.floor_color < 0 || game->graphics.ceiling_color < 0) {
		perror("Invalid floor/ceiling color"), game->is_error = EXIT_FAILURE;
	}
}

int	init_graphics(t_game *game)
{
	if (!game)
        return (perror("init_graphics: Window init failure!"), 1);
	if (init_window(game))
		return (perror("init_graphics: win game pointer"), 1);
	init_images(game);
	if (game->is_error)
		exit(EXIT_FAILURE); // <-- Reaplace with some safe exit programm with cleaning of all data
}
