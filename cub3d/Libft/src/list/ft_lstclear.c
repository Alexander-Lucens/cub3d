/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:40:01 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:15 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// static int	nb_free_done;
// void	ft_del(void *content)
// {
// 	free(content);
// 	nb_free_done++;
// }
// t_list	*ft_lstnewone(void *content)
// {
// 	t_list	*elem;
// 	elem = (t_list *)malloc(sizeof(t_list));
// 	if (!elem)
// 		return (NULL);
// 	if (!content)
// 		elem->content = NULL;
// 	else
// 		elem->content = content;
// 	elem->next = NULL;
// 	return (elem);
// }
// int main()
// {
// 	t_list		*elem;
// 	t_list		*elem2;
// 	t_list		*elem3;
// 	t_list		*elem4;
// 	char		*str = strdup("lorem");
// 	char		*str2 = strdup("ipsum");
// 	char		*str3 = strdup("dolor");
// 	char		*str4 = strdup("sit");
// 	elem = ft_lstnewone(str);
// 	elem2 = ft_lstnewone(str2);
// 	elem3 = ft_lstnewone(str3);
// 	elem4 = ft_lstnewone(str4);
// 	elem->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = elem4;
// 	nb_free_done = 0;
// 	ft_lstclear(&elem3, &ft_del);
// 	if (elem)
// 		printf("%p\n",elem);
// 	else
// 		write(1, "NULL", 4);
// 	if (elem2)
// 		printf("%p\n",elem2);
// 	else
// 		write(1, "NULL", 4);
// 	if (elem3)
// 		printf("%p\n",elem3);
// 	else
// 		write(1, "NULL", 4);
// 	if (elem4)
// 	{
// 		write(1, "nb_free_done = ", 15);
// 		nb_free_done += '0';
// 		write(1, &nb_free_done, 1);
// 	}
// 	else
// 		write(1, "NULL", 4);
// 	return (0);
// }
