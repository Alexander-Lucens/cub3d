/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	write_x(t_player *p, t_render_data *rd)
{
	if (rd->ray_dir.x < 0)
	{
		rd->step_x = -1;
		rd->side_dist.x = (p->pos.x - rd->map_x) * rd->delta_dist.x;
	}
	else
	{
		rd->step_x = 1;
		rd->side_dist.x = (rd->map_x + 1.0 - p->pos.x) * rd->delta_dist.x;
	}
}

static void	write_y(t_player *p, t_render_data *rd)
{
	if (rd->ray_dir.y < 0)
	{
		rd->step_y = -1;
		rd->side_dist.y = (p->pos.y - rd->map_y) * rd->delta_dist.y;
	}
	else
	{
		rd->step_y = 1;
		rd->side_dist.y = (rd->map_y + 1.0 - p->pos.y) * rd->delta_dist.y;
	}
}

void	init_render_data(t_player *p, int x, t_render_data *rd)
{
	rd->camera_x = 2 * x / (float)DEF_WIN_WIDTH - 1;
	rd->ray_dir = tpos(p->dir.x + p->plane.x * rd->camera_x,
			p->dir.y + p->plane.y * rd->camera_x);
	rd->map_x = (int)p->pos.x;
	rd->map_y = (int)p->pos.y;
	rd->delta_dist = tpos(fabsf(1 / rd->ray_dir.x), fabsf(1 / rd->ray_dir.y));
	write_x(p, rd);
	write_y(p, rd);
	rd->hit = 0;
}
