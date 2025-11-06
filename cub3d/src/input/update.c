/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/06 18:27:10 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int update(t_game *game)
{
    t_pos       move;
    t_pos       new;
    long long   current_time;
    long long   elapsed;

    if (game->player.controls.left)
        rotate_player(game, -1);
    if (game->player.controls.right)
        rotate_player(game, 1);

    current_time = get_time_in_us();
    elapsed = current_time - game->player.last_update_time;

    if (elapsed < FRAME_INTERVAL)
        return (display_game(game), 0);

    game->player.last_update_time = current_time;

    move = init_tpos();
    if (game->player.controls.w)
    {
        move.x += game->player.dir.x * MOVE_SPEED;
        move.y += game->player.dir.y * MOVE_SPEED;
    }
    if (game->player.controls.s)
    {
        move.x -= game->player.dir.x * MOVE_SPEED;
        move.y -= game->player.dir.y * MOVE_SPEED;
    }

    if (game->player.controls.a)
    {
        move.x -= game->player.plane.x * MOVE_SPEED;
        move.y -= game->player.plane.y * MOVE_SPEED;
    }
    if (game->player.controls.d)
    {
        move.x += game->player.plane.x * MOVE_SPEED;
        move.y += game->player.plane.y * MOVE_SPEED;
    }
    if (move.x != 0.0f || move.y != 0.0f)
    {
        new = tpos(game->player.pos.x + move.x, game->player.pos.y + move.y);
        if (!is_invalid_move(game, tpos(new.x, game->player.pos.y)))
            game->player.pos.x = new.x;
        if (!is_invalid_move(game, tpos(game->player.pos.x, new.y)))
            game->player.pos.y = new.y; 
    }
    display_game(game);
    return (0);
}
