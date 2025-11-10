/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 18:41:43 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_buffer(t_game *game)
{
	game->graphics.buffer.img = mlx_new_image(game->graphics.mlx,
			DEF_WIN_WIDTH, DEF_WIN_HEIGHT);
	if (!game->graphics.buffer.img)
		return (1);
	game->graphics.buffer.addr = mlx_get_data_addr(
			game->graphics.buffer.img,
			&game->graphics.buffer.bpp,
			&game->graphics.buffer.line_len,
			&game->graphics.buffer.endian
			);
	return (0);
}

static int	init_window(t_game *game)
{
	int	width;
	int	height;

	width = DEF_WIN_WIDTH;
	height = DEF_WIN_HEIGHT;
	game->graphics.window = mlx_new_window(game->graphics.mlx,
			width, height, "cub3d");
	if (!game->graphics.window)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	load_texture(t_graphics *gfx, t_image *tex, char *path)
{
	if (!path)
		return (print_error("Texture path is NULL"), 1);
	if (access(path, F_OK) != 0)
		return (print_error("Texture is Not Found"), 1);
	tex->img = mlx_xpm_file_to_image(gfx->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (print_error("failed to load texture"), 1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (print_error("mlx_get_data_addr failed"), 1);
	return (0);
}

static int	init_images(t_game *game)
{
	t_graphics		*gr;
	t_parsed_data	*d;

	gr = &game->graphics;
	d = &game->data;
	if (load_texture(gr, &gr->north, d->north_texture_path)
		|| load_texture(gr, &gr->south, d->south_texture_path)
		|| load_texture(gr, &gr->east, d->east_texture_path)
		|| load_texture(gr, &gr->west, d->west_texture_path))
		return (print_error("failed to load texture"), 1);
	gr->floor_color = create_int_rgb(d->floor);
	gr->ceiling_color = create_int_rgb(d->ceiling);
	if (gr->floor_color < 0 || gr->ceiling_color < 0)
		return (print_error("Invalid floor/ceiling color"), 1);
	return (0);
}

int	init_graphics(t_game *game)
{
	if (!game)
		return (print_error("init_graphics: game pointer is NULL"), 1);
	game->graphics.mlx = mlx_init();
	if (!game->graphics.mlx)
		return (print_error("mlx_init failed"), 1);
	if (init_window(game))
		return (print_error("window can not be loaded"), 1);
	if (init_images(game))
		return (print_error("images can not be loaded"), 1);
	if (init_buffer(game))
		return (print_error("Buffer can not be loaded"), 1);
	return (0);
}
