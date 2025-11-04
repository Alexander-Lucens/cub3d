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

#include "../../includes/cub3d.h"

// int	key_press(int keycode, t_game *game)
// {
// 	if (KEY_W(keycode))
// 		game->player.controls.w = 1;
// 	else if (KEY_S(keycode))
// 		game->player.controls.s = 1;
// 	else if (KEY_A(keycode))
// 		game->player.controls.a = 1;
// 	else if (KEY_D(keycode))
// 		game->player.controls.d = 1;
// 	else if (L_ARROW(keycode))
// 		game->player.controls.left = 1;
// 	else if (R_ARROW(keycode))
// 		game->player.controls.right = 1;
// 	else if (KEY_EXIT(keycode))
// 		exit(1); // replace with custom cleenup and exit function
// 	return (0);
// }

// int	key_release(int keycode, t_game *game)
// {
// 	if (KEY_W(keycode))
// 		game->player.controls.w = 0;
// 	else if (KEY_S(keycode))
// 		game->player.controls.s = 0;
// 	else if (KEY_A(keycode))
// 		game->player.controls.a = 0;
// 	else if (KEY_D(keycode))
// 		game->player.controls.d = 0;
// 	else if (L_ARROW(keycode))
// 		game->player.controls.left = 0;
// 	else if (R_ARROW(keycode))
// 		game->player.controls.right = 0;
// 	return (0);
// }

// // convert int to float
// int	update(t_game *game)
// {
// 	if (game->player.delay > 0)
// 	{
// 		game->player.delay--;
// 		return (0);
// 	}
// 	if (game->player.controls.w || game->player.controls.s || game->player.controls.a || game->player.controls.d)
// 	{
// 		if (game->player.controls.w)
// 			move_player(game, 0, -1);
// 		if (game->player.controls.s)
// 			move_player(game, 0, 1);
// 		if (game->player.controls.a)
// 			move_player(game, -1, 0);
// 		if (game->player.controls.d)
// 			move_player(game, 1, 0);
// 		game->player.delay = MOVE_DELAY;
// 	}
// 	return (0);
// }
