/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:09 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 03:14:54 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_extension(char *map, t_game *game)
{
	int	i;

	i = ft_strlen(map);
	if (i >= 4 && ft_strncmp(map + i - 4, ".ber", 4) != 0)
		ft_error(game, 1);
}
