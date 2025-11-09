/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:14 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

/* INCLUDES *************************************************************** */

# include "cub3d.h"
/* ************************************************************************ */

/* STRUCTS **************************************************************** */

typedef struct s_render_data
{
	t_pos	ray_dir;
	t_pos	side_dist;
	t_pos	delta_dist;
	float	camera_x;
	float	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_render_data;
/* ************************************************************************ */

/* RENDER ***************************************************************** */

void	init_render_data(t_player *p, int x, t_render_data *rd);
void	draw_wall(t_game *game, int x, t_render_data *rd);
void	display_game(t_game *game);
/* ************************************************************************ */
#endif
