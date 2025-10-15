/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 07:54:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putbase(unsigned long n, int uppercase, int base)
{
	char			*chars;
	char			value[65];
	int				i;

	if (uppercase)
		chars = "0123456789ABCDEF";
	else
		chars = "0123456789abcdef";
	i = 64;
	value[i--] = '\0';
	if (n == 0)
		value[i--] = '0';
	while (n > 0)
	{
		value[i--] = chars[n % base];
		n /= base;
	}
	return (ft_putstr(&value[i + 1]));
}
