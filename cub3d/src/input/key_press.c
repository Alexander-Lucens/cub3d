/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 04:41:34 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (KEY_W(keycode))
		game->controls.w = 1;
	else if (KEY_S(keycode))
		game->controls.s = 1;
	else if (KEY_A(keycode))
		game->controls.a = 1;
	else if (KEY_D(keycode))
		game->controls.d = 1;
	else if (KEY_EXIT(keycode))
		close_game(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (KEY_W(keycode))
		game->controls.w = 0;
	else if (KEY_S(keycode))
		game->controls.s = 0;
	else if (KEY_A(keycode))
		game->controls.a = 0;
	else if (KEY_D(keycode))
		game->controls.d = 0;
	return (0);
}

// convert int to float
int	update(t_game *game)
{
	if (game->player.delay > 0)
	{
		game->player.delay--;
		return (0);
	}
	if (game->player.controls.w || game->player.controls.s \
		|| game->player.controls.a || game->player.controls.d)
	{
		if (game->player.controls.w)
			move_player(game, 0, -1);
		if (game->player.controls.s)
			move_player(game, 0, 1);
		if (game->player.controls.a)
			move_player(game, -1, 0);
		if (game->player.controls.d)
			move_player(game, 1, 0);
		game->player.delay = MOVE_DELAY;
	}
	return (0);
}
