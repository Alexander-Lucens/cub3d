/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:45:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

//Previous stable version, without memory leaks
// ssize_t	ft_putnbr(int n)
// {
// 	unsigned int	len;
// 	unsigned int	division;
// 	ssize_t			out_len;

// 	if (n == -2147483648)
// 		return (ft_putstr("-2147483648"));
// 	len = ft_num_len(n, 10);
// 	out_len = (ssize_t)len;
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		len--;
// 		n = -n;
// 	}
// 	division = 1;
// 	while (--len > 0)
// 		division *= 10;
// 	while (division > 0)
// 	{
// 		ft_putchar(((unsigned int)n / division) + '0');
// 		n %= division;
// 		division /= 10;
// 	}
// 	return (out_len);
// }

ssize_t	ft_putnbr(int n)
{
	ssize_t	out_len;
	ssize_t	check;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	out_len = 0;
	if (n < 0)
	{
		out_len = write(1, "-", 1);
		if (out_len == -1)
			return (out_len);
		n = -n;
	}
	check = ft_putbase(n, 0, 10);
	if (check == -1)
		return (-1);
	return (out_len + check);
}
