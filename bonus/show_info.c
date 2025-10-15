/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:43:29 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:47:08 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	moves_info(t_game *game)
{
	char	*moves_str;
	char	*moves_num;

	moves_num = ft_itoa(game->moves);
	moves_str = ft_strjoin("Moves: ", moves_num);
	free(moves_num);
	mlx_string_put(game->graphics.mlx, game->graphics.win,
		game->map.window_width + 15, game->map.window_height / 3,
		65280, moves_str);
	free(moves_str);
}

void	show_info(t_game *game)
{
	char	*coins_str;
	char	*collected;
	char	*total;
	char	*temp1;
	char	*temp2;

	moves_info(game);
	collected = ft_itoa(game->map.coins_all - game->map.coins_left);
	temp1 = ft_strjoin("Coins: ", collected);
	free(collected);
	temp2 = ft_strjoin(temp1, " / ");
	free(temp1);
	total = ft_itoa(game->map.coins_all);
	coins_str = ft_strjoin(temp2, total);
	free(temp2);
	free(total);
	mlx_string_put(game->graphics.mlx, game->graphics.win,
		game->map.window_width + 15, (game->map.window_height / 3) * 2,
		65280, coins_str);
	free(coins_str);
}
