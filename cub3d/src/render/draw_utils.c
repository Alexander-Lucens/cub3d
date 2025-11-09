/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_buffer(t_image *buffer, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= DEF_WIN_WIDTH || y < 0 || y >= DEF_WIN_HEIGHT)
		return ;
	dst = buffer->addr + (y * buffer->line_len + x * (buffer->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Get collor of texture pixel
 */
int	get_texture_pixel(t_image *tex, int x, int y)
{
	char	*src;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	src = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)src);
}

/**
 * @brief Draw floor and ceiling using collors, and skip wals.
 */
void	draw_floor_and_ceiling(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		put_pixel_to_buffer(&game->graphics.buffer, x, y,
			game->graphics.ceiling_color);
		y++;
	}
	y = draw_start;
	while (y < DEF_WIN_HEIGHT)
	{
		put_pixel_to_buffer(&game->graphics.buffer, x, y,
			game->graphics.floor_color);
		y++;
	}
}
