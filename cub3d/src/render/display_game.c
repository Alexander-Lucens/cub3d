/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/07 16:25:53 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_image *get_correct_texture(t_game *game, int side, t_pos ray_dir)
{
    if (side == 0)
    {
        if (ray_dir.x > 0)
            return (&game->graphics.east);
        else
            return (&game->graphics.west);
    }
    else
    {
        if (ray_dir.y > 0)
            return (&game->graphics.south);
        else
            return (&game->graphics.north);
    }
}

/**
 * @brief Main function to display data on screen.
 * Calls from @update().
 */
void display_game(t_game *game)
{
    int     x;
    float   camera_x;
    t_pos   ray_dir;
    int     map_x, map_y;
    t_pos   side_dist;
    t_pos   delta_dist;
    float   perp_wall_dist;
    int     step_x, step_y;
    int     hit, side;
    int     line_height, draw_start, draw_end;

    x = 0;
    while (x < DEF_WIN_WIDTH)
    {
        /** Calculate rey direction */
        camera_x = 2 * x / (float)DEF_WIN_WIDTH - 1;
        ray_dir = tpos(game->player.dir.x + game->player.plane.x * camera_x,
        	game->player.dir.y + game->player.plane.y * camera_x);

        /** Positioning on map */
        map_x = (int)game->player.pos.x;
        map_y = (int)game->player.pos.y;

        /** CALCULATE DISTANCE which ray pass before hit x or y */
        delta_dist = tpos(fabsf(1 / ray_dir.x), fabsf(1 / ray_dir.y));

        /** Begining distance from player to grid and directions
         * will be separated as addition function
         */
        if (ray_dir.x < 0)
        {
            step_x = -1;
            side_dist.x = (game->player.pos.x - map_x) * delta_dist.x;
        }
        else
        {
            step_x = 1;
            side_dist.x = (map_x + 1.0 - game->player.pos.x) * delta_dist.x;
        }
        if (ray_dir.y < 0)
        {
            step_y = -1;
            side_dist.y = (game->player.pos.y - map_y) * delta_dist.y;
        }
        else
        {
            step_y = 1;
            side_dist.y = (map_y + 1.0 - game->player.pos.y) * delta_dist.y;
        }

        /** (Digital Differential Analysis)
         * try to hit wall to get distance
         */ 
        hit = 0;
        while (hit == 0)
        {
            if (side_dist.x < side_dist.y)
            {
                side_dist.x += delta_dist.x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist.y += delta_dist.y;
                map_y += step_y;
                side = 1;
            }
            if (game->map.matrix[map_y][map_x] == CELL_WALL)
                hit = 1;
        }

        /** Calculate perpendicular distance to awoid weard displaying */
        if (side == 0)
            perp_wall_dist = (side_dist.x - delta_dist.x);
        else
            perp_wall_dist = (side_dist.y - delta_dist.y);

        /** Calculate height of current line, slice of wall */
        line_height = (int)(DEF_WIN_HEIGHT / perp_wall_dist);

        /** Calculate start and end of curent line to draw it */
        draw_start = -line_height / 2 + DEF_WIN_HEIGHT / 2;
        if (draw_start < 0)
            draw_start = 0;
        draw_end = line_height / 2 + DEF_WIN_HEIGHT / 2;
        if (draw_end >= DEF_WIN_HEIGHT)
            draw_end = DEF_WIN_HEIGHT - 1;

        draw_floor_and_ceiling(game, x, draw_start);

        /** Calculation of texture coordinates */
        t_image *tex = get_correct_texture(game, side, ray_dir);
        
        /** Textures part */
        double wall_x;
        if (side == 0)
            wall_x = game->player.pos.y + perp_wall_dist * ray_dir.y;
        else
            wall_x = game->player.pos.x + perp_wall_dist * ray_dir.x;
        wall_x -= floor(wall_x);

        int tex_x = (int)(wall_x * (double)tex->width);
        if((side == 0 && ray_dir.x > 0) || (side == 1 && ray_dir.y < 0))
            tex_x = tex->width - tex_x - 1;

        double tex_step = 1.0 * tex->height / line_height;
        double tex_pos = (draw_start - DEF_WIN_HEIGHT / 2 + line_height / 2) * tex_step;
        /** Will be separated later */

        /** Draw pixel by pixel here */
        int y;
        y = draw_start;
        while (y <= draw_end)
        {
            int tex_y = (int)tex_pos & (tex->height - 1);
            tex_pos += tex_step;
            int color = get_texture_pixel(tex, tex_x, tex_y);
            put_pixel_to_buffer(&game->graphics.buffer, x, y, color);
            y++;
        }
        
        x++;
    }
    mlx_put_image_to_window(game->graphics.mlx, game->graphics.window,
        game->graphics.buffer.img, 0, 0);
}
