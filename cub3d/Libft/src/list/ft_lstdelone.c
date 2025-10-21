/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:40:01 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/*
Оставил чисто для себя, мб пригодиться, но нужно доделать
1) Взять ноды и адрес к елементу в ноде для ужаления
2) Пройтись по ноде пока не найду что что нужно удалить при помощи free
3) Соеденить цепочку обратно
*/
// void ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	t_list *previous;
// 	t_list *after;

// 	if (lst == NULL)
// 		return ;
// 	while (lst != NULL)
// 	{
// 		previous = lst;
// 		if(lst->next == del)
// 		{
// 			lst = lst->next;
// 			after = lst->next;
// 			free(lst);
// 			previous->next = after;
// 			lst = previous;
// 		}
// 		lst = lst->next;
// 	}
// }

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
