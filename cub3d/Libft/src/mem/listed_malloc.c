/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listed_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/10 14:32:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * If you paset in path your structure and it's have list of type t_list 
 * You can store in it pointers to allocated chunks of memory in reverse order, 
 * and then use ft_lst_clear to delete all allocated memory during comand exec
 * !!! YOU NEED TO BE SHURE THAT 'list' EXIST as t_list *list
 */
void	*listed_malloc(t_list **list, size_t total_size)
{
	void	*block;

	block = malloc(total_size);
	if (!block)
		return (NULL);
	ft_memset(block, 0, sizeof(block));
	ft_lstadd_front(list, ft_lstnew(block));
	return (block);
}
