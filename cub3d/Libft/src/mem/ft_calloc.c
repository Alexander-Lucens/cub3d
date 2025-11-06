/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:37 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
	ft_memset(block, 0, total_size);
	return (block);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	total_size;
// 	void	*block;

// 	total_size = count * size;
// 	if (count != 0 && size != 0 && (total_size < count || total_size < size))
// 		return (NULL);
// 	block = malloc(total_size);
// 	if (!block)
// 		return (NULL);
// 	// ft_bzero(block, total_size);
// 	return (block);
// }