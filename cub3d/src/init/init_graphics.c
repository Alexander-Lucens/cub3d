/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/31 12:54:01 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// ALL exit(EXIT_FAILURE) MUST BE REPLACES TO --> cleanup function

int create_int_rgb(const t_rgb *color)
{
    if (!color)
        return (perror("create_int_rgb: null color pointer"), -1);
    if (color->r < 0 || color->r > 255 ||
        color->g < 0 || color->g > 255 ||
        color->b < 0 || color->b > 255)
    {
        return (perror("create_int_rgb: color value out of range"), -1);
    }
    return ((color->r << 16) | (color->g << 8) | (color->b));
}

static void init_window(t_game *game) 
{
	int	width;
	int	height;

	mlx_get_screen_size(game->graphics.mlx, &width, &height);
	if (!width || !height) {
		width = DEF_WIN_WIDTH;
		height = DEF_WIN_HEIGHT;
	}
	game->graphics.win = mlx_new_window(game->graphics.mlx, width, height, "cub3d");
	if (!game)
}

static int	check_images_init(t_game *game)
{
	int is_error;

	is_error = 0;
	if (!game->graphics.east_texture)
		perror("Failed to load east texture"), is_error++;
	if (!game->graphics.west_te)
		perror("Failed to load west texture"), is_error++;
	if (!game->graphics.east_texture)
		perror("Failed to load east texture"), is_error++;
}

static void	load_texture(t_graphics *gfx, t_image *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(gfx->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr_fd("Error: failed to load texture: ", 2);
		ft_putendl_fd(path, 2);
		exit(EXIT_FAILURE);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
}

// Image size predefined and set in defines.h as 10
static void	init_images(t_game *game)
{
	int	size;

	size = IMG_SIZE;
	load_texture(game->graphics, game->graphics.north, game->data.north_texture_path);
	load_texture(game->graphics, game->graphics.south, game->data.south_texture_path);
	load_texture(game->graphics, game->graphics.east, game->data.east_texture_path);
	load_texture(game->graphics, game->graphics.west, game->data.west_texture_path);
	
	game->graphics.floor_color = create_int_rgb(game->data.floor);
	game->graphics.ceiling_color = create_int_rgb(game->data.ceiling);
	if (game->graphics.floor_color < 0 || game->graphics.ceiling_color < 0) {
		perror("Invalid floor/ceiling color"), exit(EXIT_FAILURE);
	}
}

void	init_graphics(t_game *game)
{
	if (!game)
    {
        perror("init_graphics: null game pointer");
        exit(EXIT_FAILURE);
    }
	init_window(game);
	init_images(game);
	
}
