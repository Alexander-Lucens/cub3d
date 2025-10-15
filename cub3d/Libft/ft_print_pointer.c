/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:45:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 07:54:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for linus (nil) for macOS 0x0
ssize_t	ft_print_pointer(void *ptr)
{
	if (ptr == NULL)
		return (ft_putstr("0x0"));
	if (ft_putstr("0x") == -1)
		return (-1);
	return (ft_putbase((unsigned long)ptr, 0, 16) + 2);
}
