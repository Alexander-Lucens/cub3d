/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 17:16:13 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief 
 * 
 * @param
 */
void	exit_game(t_game *game, int exit_code)
{
	s_free(game);
	exit(exit_code);
}

