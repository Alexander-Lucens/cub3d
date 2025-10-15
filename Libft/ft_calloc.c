/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 07:54:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*block;

	total_size = count * size;
	if (count != 0 && size != 0 && (total_size < count || total_size < size))
		return (NULL);
	block = malloc(total_size);
	if (!block)
		return (NULL);
	ft_bzero(block, total_size);
	return (block);
}

/*
#include <stdio.h>
int main()
{
	printf("STD: %s |  %p \n", (char *)calloc((INT64_MAX) , 2),\
	 calloc((INT64_MAX), 2));
	printf("CTD: %s |  %p \n", (char *)ft_calloc((INT64_MAX), 2),\
	 ft_calloc((INT64_MAX), 2));
	printf("STD: %s |  %p \n", (char *)calloc(0, 0),\
	 calloc(0, 0));
	printf("CTD: %s |  %p \n", (char *)ft_calloc(0, 0),\
	 ft_calloc(0, 0));
	return (0);
	char *p = ft_calloc(0, 5);
	check(p != NULL); free(p); showLeaks();
	p = ft_calloc(5, 0);
	check(p != NULL); free(p); showLeaks();
	check(p != NULL); free(p); showLeaks();
	p = ft_calloc(-5, 0);
	check(p != NULL); free(p); showLeaks();
}
*/
