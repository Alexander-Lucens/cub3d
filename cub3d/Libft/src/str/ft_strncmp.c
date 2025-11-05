/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 00:41:00 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		out;

	i = 0;
	out = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || !s1[i] || !s2[i])
		{
			out = ((unsigned char)s1[i] - (unsigned char)s2[i]);
			break ;
		}
		i++;
	}
	if (out > 127)
		return (1);
	if (out < -127)
		return (-1);
	return (out);
}
