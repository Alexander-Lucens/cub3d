/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 02:19:22 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length_dest;
	size_t	length_src;
	size_t	i;

	length_src = 0;
	while (src[length_src] != '\0')
		length_src++;
	length_dest = 0;
	while (dst[length_dest] != '\0' && dstsize > length_dest)
		length_dest++;
	if (dstsize <= length_dest)
		return (dstsize + length_src);
	i = 0;
	while (src[i] != '\0' && (length_dest + i) < (dstsize - 1))
	{
		dst[length_dest + i] = src[i];
		i++;
	}
	dst[length_dest + i] = '\0';
	return (length_dest + length_src);
}
