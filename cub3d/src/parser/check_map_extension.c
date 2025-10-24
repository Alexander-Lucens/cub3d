/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:09 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 19:45:32 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_extension(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i >= 4 && ft_strncmp(map + i - 4, ".cub", 4) != 0)
		printf("Wrong extension");
	// ft_error(game, 1);
}
