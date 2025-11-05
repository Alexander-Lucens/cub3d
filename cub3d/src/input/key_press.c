/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 10:50:55 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_game *game, int exit_code);

int	key_press(int keycode, t_game *game)
{
	if (KEY_W(keycode))
		game->player.controls.w = 1;
	else if (KEY_S(keycode))
		game->player.controls.s = 1;
	else if (KEY_A(keycode))
		game->player.controls.a = 1;
	else if (KEY_D(keycode))
		game->player.controls.d = 1;
	else if (L_ARROW(keycode))
		game->player.controls.left = 1;
	else if (R_ARROW(keycode))
		game->player.controls.right = 1;
	else if (KEY_EXIT(keycode))
		exit_game(game, 0);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (KEY_W(keycode))
		game->player.controls.w = 0;
	else if (KEY_S(keycode))
		game->player.controls.s = 0;
	else if (KEY_A(keycode))
		game->player.controls.a = 0;
	else if (KEY_D(keycode))
		game->player.controls.d = 0;
	else if (L_ARROW(keycode))
		game->player.controls.left = 0;
	else if (R_ARROW(keycode))
		game->player.controls.right = 0;
	return (0);
}

void	rotate_player(t_game *game, int dir)
{
    float	old_dir_x;
    float	old_plane_x;
    float	rotation_speed;

    rotation_speed = 0.05 * dir;
    old_dir_x = game->player.dir.x;
    game->player.dir.x = game->player.dir.x * cos(rotation_speed)
        - game->player.dir.y * sin(rotation_speed);
    game->player.dir.y = old_dir_x * sin(rotation_speed)
        + game->player.dir.y * cos(rotation_speed);
    old_plane_x = game->player.plane.x;
    game->player.plane.x = game->player.plane.x * cos(rotation_speed)
        - game->player.plane.y * sin(rotation_speed);
    game->player.plane.y = old_plane_x * sin(rotation_speed)
        + game->player.plane.y * cos(rotation_speed);
}
