/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:49:22 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->exit_status == 0)
		ft_printf("You win! Moves: %d\n", game->moves);
	else if (game->exit_status == 1)
		ft_printf("You Lose! Moves: %d\n");
	s_free(game);
	exit(0);
	return (0);
}
