/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/20 13:10:25 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 119)
		game->controls.w = 1;
	else if (keycode == 1 || keycode == 115)
		game->controls.s = 1;
	else if (keycode == 0 || keycode == 97)
		game->controls.a = 1;
	else if (keycode == 2 || keycode == 100)
		game->controls.d = 1;
	else if (keycode == 53 || keycode == 65307)
		close_game(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 119)
		game->controls.w = 0;
	else if (keycode == 1 || keycode == 115)
		game->controls.s = 0;
	else if (keycode == 0 || keycode == 97)
		game->controls.a = 0;
	else if (keycode == 2 || keycode == 100)
		game->controls.d = 0;
	return (0);
}

// convert int to float
int	update(t_game *game)
{
	if (game->move_cooldown > 0)
	{
		game->move_cooldown--;
		return (0);
	}
	if (game->controls.w || game->controls.s || game->controls.a || game->controls.d)
	{
		if (game->controls.w)
			move_player(game, 0, -1);
		if (game->controls.s)
			move_player(game, 0, 1);
		if (game->controls.a)
			move_player(game, -1, 0);
		if (game->controls.d)
			move_player(game, 1, 0);
		game->move_cooldown = MOVE_DELAY;
	}
	return (0);
}
