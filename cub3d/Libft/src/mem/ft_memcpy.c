/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:37 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (n == 0 || (dst == NULL && src == NULL))
		return (dst);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char *place;

	place = "            ";
	printf("Data before: %s\nPointer before: %p\n", place, place);
	printf("\nMy otput:\n");
	ft_memcpy(place, ((void *)0), 17);
	printf("Data: %s\nPointer: %p\n", place, place);

	printf("\nStandart otput:\n");
	place = "            ";
	memcpy(place, ((void *)0), 17);
	printf("Data: %s\nPointer: %p\n", place, place);

}
*/
