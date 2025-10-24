/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:17:45 by lkramer           #+#    #+#             */
/*   Updated: 2025/10/24 19:40:52 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * @brief Checker for white spaces and end of string
 * 
 * @return int * 
 */
int	check_white_spaces_end_of_str(char **lines, int *i)
{
	int	j;

	if (lines[*i][0] == '\0')
    {
        (*i)++;
        return (1);
    }
    j = 0;
    while (lines[*i][j])
    {
        if (lines[*i][j] != ' ' && lines[*i][j] != '\t' 
			&& lines[*i][j] != '\n')
            return (0);
        j++;
    }
    (*i)++;
    return (1);
}


void	free_split(char **split)
{
    int	i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
