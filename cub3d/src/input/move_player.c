/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/06 15:29:08 by akuzmin          ###   ########.fr       */
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
int is_invalid_move(t_game *game, t_pos new_pos)
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
