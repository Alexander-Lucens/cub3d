/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 02:19:22 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == src || len == 0)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
		d[len] = s[len];
	return (dst);
}

/*
#include <stdio.h>
int main(void) {
    int size = 10;
    char *dst = malloc(size);
    char *data = malloc(size);

    for (int i = 0; i < size; i++) {
        data[i] = 'A';
    }

    ft_memmove(dst, data, size);
    printf("After memmove, dst: %s\n", dst);

    free(dst);
    free(data);

    return 0;
}
*/
