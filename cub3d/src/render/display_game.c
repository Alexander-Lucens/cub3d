/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	perform_dda(t_game *game, t_render_data *rd)
{
	while (!rd->hit)
	{
		if (rd->side_dist.x < rd->side_dist.y)
		{
			rd->side_dist.x += rd->delta_dist.x;
			rd->map_x += rd->step_x;
			rd->side = 0;
		}
		else
		{
			rd->side_dist.y += rd->delta_dist.y;
			rd->map_y += rd->step_y;
			rd->side = 1;
		}
		if (game->map.matrix[rd->map_y][rd->map_x] == CELL_WALL)
			rd->hit = 1;
	}
	if (rd->side == 0)
		rd->perp_wall_dist = rd->side_dist.x - rd->delta_dist.x;
	else
		rd->perp_wall_dist = rd->side_dist.y - rd->delta_dist.y;
}

static void	calculate_line(t_render_data *rd)
{
	rd->line_height = (int)(DEF_WIN_HEIGHT / rd->perp_wall_dist);
	rd->draw_start = -rd->line_height / 2 + DEF_WIN_HEIGHT / 2;
	if (rd->draw_start < 0)
		rd->draw_start = 0;
	rd->draw_end = rd->line_height / 2 + DEF_WIN_HEIGHT / 2;
	if (rd->draw_end >= DEF_WIN_HEIGHT)
		rd->draw_end = DEF_WIN_HEIGHT - 1;
}

void	display_game(t_game *game)
{
	int				x;
	t_render_data	rd;

	x = -1;
	while (++x < DEF_WIN_WIDTH)
	{
		init_render_data(&game->player, x, &rd);
		perform_dda(game, &rd);
		calculate_line(&rd);
		draw_wall(game, x, &rd);
	}
	mlx_put_image_to_window(game->graphics.mlx,
		game->graphics.window,
		game->graphics.buffer.img,
		0, 0);
}
