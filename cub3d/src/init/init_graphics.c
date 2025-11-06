/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:29:11 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_int_rgb(const t_rgb *color);

void    init_buffer(t_game *game)
{
    game->graphics.buffer.img = mlx_new_image(game->graphics.mlx,
            DEF_WIN_WIDTH, DEF_WIN_HEIGHT);
    if (!game->graphics.buffer.img)
    {
        ft_error(game, 103);
        return;
    }
    game->graphics.buffer.addr = mlx_get_data_addr(
            game->graphics.buffer.img,
            &game->graphics.buffer.bpp,
            &game->graphics.buffer.line_len,
            &game->graphics.buffer.endian
            );
}

static int init_window(t_game *game) 
{
	int	width;
	int	height;

	width = DEF_WIN_WIDTH;
	height = DEF_WIN_HEIGHT;	
	game->graphics.window = mlx_new_window(game->graphics.mlx, \
		width, height, "cub3d");
	if (!game->graphics.window)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_texture(t_graphics *gfx, t_image *tex, char *path)
{
	if (!path)
		return (PRINT_ERROR("Texture path is NULL"), 1);
	if (access(path, F_OK) != 0)
	{
		perror("Texture file not found");
		fprintf(stderr, "Missing texture: %s\n", path);
		return (1);
	}
	tex->img = mlx_xpm_file_to_image(gfx->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (PRINT_ERROR("failed to load texture"), 1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
	if (!tex->addr)
        return (PRINT_ERROR("mlx_get_data_addr failed"), 1);
	return (0);
}

// Image size predefined and set in defines.h as 10
static int	init_images(t_game *game)
{
	if (load_texture(&game->graphics, &game->graphics.north, game->data.north_texture_path)
		|| load_texture(&game->graphics, &game->graphics.south, game->data.south_texture_path)
		|| load_texture(&game->graphics, &game->graphics.east, game->data.east_texture_path)
		|| load_texture(&game->graphics, &game->graphics.west, game->data.west_texture_path) )
		return (PRINT_ERROR("failed to load texture"), 1);
	game->graphics.floor_color = create_int_rgb(game->data.floor);
	game->graphics.ceiling_color = create_int_rgb(game->data.ceiling);
	if (game->graphics.floor_color < 0 || game->graphics.ceiling_color < 0) {
		return (PRINT_ERROR("Invalid floor/ceiling color"), 1);
	}
	return (0);
}

int	init_graphics(t_game *game)
{
	if (!game)
        return (PRINT_ERROR("init_graphics: game pointer is NULL"), 1);
	game->graphics.mlx = mlx_init();
	if (!game->graphics.mlx)
		return (PRINT_ERROR("mlx_init failed"), 1);
	if (init_window(game))
		return (PRINT_ERROR("window can not be loaded"), \
			cleanup_graphics(game), 1);
	if (init_images(game))
		return (PRINT_ERROR("images can not be loaded"), \
			cleanup_graphics(game), 1);
	init_buffer(game);
	return (0);
}
