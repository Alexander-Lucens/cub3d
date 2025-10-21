/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:17:45 by lkramer           #+#    #+#             */
/*   Updated: 2025/10/21 19:21:42 by lkramer          ###   ########.fr       */
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
	if (lines[*i][0] == '\0' || lines[*i] == ' ' 
		|| lines[*i] == '\t' || lines[*i] == '\n')
	{
		(*i)++;
		return (1);
	}
	return (0);
}