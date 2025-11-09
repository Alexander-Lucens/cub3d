/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:45:53 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:15 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

ssize_t	print(char specifier, va_list *ap)
{
	ssize_t	len;

	len = 0;
	if (specifier == 'c')
		len += ft_putchar((char)va_arg(*ap, int));
	else if (specifier == 's')
		len += ft_putstr((char *)va_arg(*ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_putnbr((int)va_arg(*ap, int));
	else if (specifier == 'p')
		len += ft_print_pointer((void *)va_arg(*ap, void *));
	else if (specifier == '%')
		len += ft_putchar('%');
	else if (specifier == 'u')
		len += ft_putbase((unsigned int)va_arg(*ap, unsigned int), 0, 10);
	else if (specifier == 'x')
		len += ft_putbase((unsigned int)va_arg(*ap, unsigned int), 0, 16);
	else if (specifier == 'X')
		len += ft_putbase((unsigned int)va_arg(*ap, unsigned int), 1, 16);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	ssize_t	len;
	ssize_t	check;

	va_start(list, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str)
				check = print(*str, &list);
			else
				break ;
		}
		else
			check = ft_putchar(*str);
		if (check == -1)
			return (check);
		len += check;
		str++;
	}
	va_end(list);
	return ((int)(len));
}
