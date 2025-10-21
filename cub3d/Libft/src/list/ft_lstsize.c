/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:40:01 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 02:19:21 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nodec;

	nodec = 0;
	while (lst != NULL)
	{
		nodec++;
		lst = lst->next;
	}
	return (nodec);
}
