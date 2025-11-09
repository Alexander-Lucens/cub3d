/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statusPrints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:24:50 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Prints in console colarful FAIL message
 * @param msg - message to print
 * @return 1 as for error/fail return
 */
int PRINT_FAIL(char *msg)
{
	ft_printf("%s%s FAIL %s%s %s %s\n",
		BG_RED, WHITE, RESET, RED, msg, RESET);
	return (1);
}

/**
 * @brief Prints in console colarful ERROR message
 * @param msg - message to print
 * @return 1 as for error/fail return
 */
int PRINT_ERROR(char *msg)
{
	ft_printf("%s%s ERROR %s%s %s %s\n",
		BG_RED, WHITE, RESET, RED, msg, RESET);
	return (1);
}

/**
 * @brief Prints in console colarful SUCCESS message
 * @param msg - message to print
 * @return 0 as for successful return
 */
int PRINT_SUCCESS(char *msg)
{
	ft_printf("%s%s SUCCESS %s%s %s %s\n",
		BG_GREEN, BLACK, RESET, GREEN, msg, RESET);
	return (0);
}

