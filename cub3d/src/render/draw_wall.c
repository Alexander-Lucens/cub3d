/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_image	*get_wall_texture(t_game *game, t_render_data *rd)
{
	if (rd->side == 0 && rd->ray_dir.x > 0)
		return (&game->graphics.west);
	if (rd->side == 0 && rd->ray_dir.x < 0)
		return (&game->graphics.east);
	if (rd->side == 1 && rd->ray_dir.y > 0)
		return (&game->graphics.north);
	return (&game->graphics.south);
}

static int	return_tex_x(t_game *game, t_image	*tex, t_render_data *rd)
{
	int		tex_x;
	double	wall_x;

	if (rd->side == 0)
		wall_x = game->player.pos.y + rd->perp_wall_dist * rd->ray_dir.y;
	else
		wall_x = game->player.pos.x + rd->perp_wall_dist * rd->ray_dir.x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	return (tex_x);
}

void	draw_wall(t_game *game, int x, t_render_data *rd)
{
	t_image	*tex;
	double	tex_step;
	double	tex_pos;
	int		tex_x;
	int		y;

	tex = get_wall_texture(game, rd);
	draw_floor_and_ceiling(game, x, rd->draw_start);
	tex_x = return_tex_x(game, tex, rd);
	if ((rd->side == 0 && rd->ray_dir.x > 0)
		|| (rd->side == 1 && rd->ray_dir.y < 0))
		tex_x = tex->width - tex_x - 1;
	tex_step = 1.0 * tex->height / rd->line_height;
	y = rd->draw_start - 1;
	tex_pos = (rd->draw_start - DEF_WIN_HEIGHT
			/ 2 + rd->line_height / 2) * tex_step;
	while (++y <= rd->draw_end)
	{
		tex_pos += tex_step;
		put_pixel_to_buffer(&game->graphics.buffer, x, y,
			get_texture_pixel(tex, tex_x, ((int)tex_pos & (tex->height - 1))));
	}
}
