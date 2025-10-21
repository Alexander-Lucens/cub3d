/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:37 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_pos	init_tpos(int x, int y)
{
	t_pos	out;

	out.x = x;
	out.y = y;
	return (out);
}

void	check_border(t_game *game)
{
	t_pos	d;
	t_pos	p;
	t_pos	n;

	p = init_tpos(0, 0);
	d = init_tpos(1, 0);
	n = init_tpos(p.x + d.x, p.y + d.y);
	while (n.x != 0 || n.y != 0)
	{
		if (n.x < game->map.cols && n.y < game->map.rows \
			&& n.x >= 0 && n.y >= 0)
		{
			p = init_tpos(n.x, n.y);
			if (game->map.matrix[p.y][p.x] != '1')
				ft_error(game, 104);
		}
		else
			d = init_tpos(-(d.y), d.x);
		n = init_tpos(p.x + d.x, p.y + d.y);
	}
}
