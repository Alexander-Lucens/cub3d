/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:13:32 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:14 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
ssize_t			ft_putchar(char c);
ssize_t			ft_putnbr(int n);
ssize_t			ft_putstr(char *s);
ssize_t			ft_print_pointer(void *ptr);
ssize_t			ft_putbase(unsigned long n, int uppercase, int baselen);

#endif
