/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:18:28 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * ToDo
 * 
 * I think need re_write error handling 
 * depending on current possibe errors
 */

static void	code_100(int status_code)
{
	if (status_code == 100)
		ft_printf("Error code: %d: File not found!\n", status_code);
	else if (status_code == 101)
		ft_printf("Error code: %d: MLX initialisation error!\n", status_code);
	else if (status_code == 102)
		ft_printf("Error code: %d: \
			Map is not rectangle, or Invalid character in map.\n", \
			status_code);
	else if (status_code == 103)
		ft_printf("Error code: %d: Grafic Initialisation problem\n", \
			status_code);
	else if (status_code == 104)
		ft_printf("Error code: %d: Map Border Error!\n", status_code);
	else if (status_code == 105)
		ft_printf("Error code: %d: Invalid size of map.\n", status_code);
}

static void	code_200(int status_code)
{
	if (status_code == 200)
		ft_printf("Error code: %d: There is no player!\n", status_code);
	else if (status_code == 201)
		ft_printf("Error code: %d: \
			Is not posible to to collect all coins or finish game!\n", \
			status_code);
	else if (status_code == 202)
		ft_printf("Error code: %d: There is no EXIT!\n", status_code);
	else if (status_code == 204)
		ft_printf("Error code: %d: Amount of players not equal 1\
			\nAmount of exits is not equalt 1.\n", status_code);
	else if (status_code == 205)
		ft_printf("Error code: %d: \
			Amount of coins is 0. Should be at least 1.\n", status_code);
}

int	ft_error(t_game *game, int status_code)
{
	if (status_code == 1)
		ft_printf("Error code: %d: Invalid map extension. Must be .cub\n", \
			status_code);
	code_100(status_code);
	code_200(status_code);
	close_game(game);
	return (1);
}
