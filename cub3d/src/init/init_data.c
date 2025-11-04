/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/31 11:07:40 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/** 
 * @brief Read file from given fd and allocated and assigned data as a string.
 * All \n and EOF is saved.
 * 
 * @param game 
 * @param fd 
 * @return char* 
 */
char	*read_file(int fd)
{
	char	*out;
	char	*temp;
	char	*line;

	line = get_next_line(fd);
	out = ft_strdup("");
	while (line != NULL)
	{
		temp = ft_strjoin(out, line);
		free(out);
		out = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (out);
}

/**
 * @brief Initialize and validate parsed file data 
 * 
 * @param game 
 * @param map_address 
 * @return int * 
 */
int	init_data(t_game *game, char *map_address)
{
	if (!parse_cub_file(game, map_address))
		return (-1);
	if (!validate_all_data(game))
        return (-1);
	/* 	if (!init_graphics(game))
        return (-1); */
	return (0);
}
