/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:22 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 11:57:33 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	testing(void);

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (PRINT_ERROR("Usage: ./cub3d <./maps/some_map.cub>\n"), 1);
	if (testing())
		return (PRINT_ERROR("Invalid parsing\n"), 1);

	(void)av;
	(void)ac;
	(void)game;
	
	return (PRINT_SUCCESS("Program finished as expected!"), 0);
}




