/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:16 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	tpos(float x, float y)
{
	t_pos	out;

	out.x = x;
	out.y = y;
	return (out);
}

t_pos	init_tpos(void)
{
	t_pos	out;

	out.x = 0.0f;
	out.y = 0.0f;
	return (out);
}

void	tpos_add(t_pos *data, float x, float y)
{
	data->x += x;
	data->y += y;
}

void	tpos_sub(t_pos *data, float x, float y)
{
	data->x -= x;
	data->y -= y;
}
