/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:15 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static char	*ft_allocation(char const *s, unsigned int start, size_t *len)
{
	size_t	s_len;
	char	*out;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		out = malloc(1);
		if (!out)
			return (NULL);
		out[0] = '\0';
		*len = 0;
		return (out);
	}
	if (*len > s_len - start)
		*len = s_len - start;
	out = malloc(*len + 1);
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;

	out = NULL;
	if (!s)
		return (NULL);
	out = ft_allocation(s, start, &len);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		out[i] = s[i + start];
		i++;
	}
	out[len] = '\0';
	return (out);
}
