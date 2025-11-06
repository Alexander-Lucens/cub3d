/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 10:51:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Checks if the player can move to the specified position.
 * 
 * @param game Pointer to the game structure.
 * @param new_pos The new position the player wants to move to.
 * @return int 1 if the move is invalid, 0 otherwise.
 */
static int	is_invalid_move(t_game *game, t_pos new_pos)
{
    int grid_x = (int)floor(new_pos.x);
    int grid_y = (int)floor(new_pos.y);

    // Check if the new position is out of bounds
    if (grid_x < 0 || grid_x >= game->map.map_width ||
        grid_y < 0 || grid_y >= game->map.map_height)
        return (1);

    // Check if the new position is a wall or void
    if (game->map.matrix[grid_y][grid_x] == CELL_WALL || 
        game->map.matrix[grid_y][grid_x] == CELL_VOID)
        return (1);

    return (0);
}


int update(t_game *game)
{
    t_pos   move;
    t_pos   new;

    
    if (game->player.controls.left)
        rotate_player(game, -1);
    if (game->player.controls.right)
        rotate_player(game, 1);
    if (game->player.delay > 0)
        return (game->player.delay--, /*display_game(game),*/ 0);
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
        game->player.delay = MOVE_DELAY;
    }
    // display_game(game);
    return (0);
}
