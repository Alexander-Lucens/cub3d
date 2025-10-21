/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 02:19:22 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	in_set(char s, char *set)
{
	while (*set)
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && in_set(s1[start], (char *)set))
		start++;
	end = ft_strlen(s1);
	while (end > start && in_set(s1[end - 1], (char *)set))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	new = malloc(end - start + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1 + start, (end - start + 1));
	return (new);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *strtrim;
// 	char s1[] = "lorem ipsum dolor sit amet";
//     if (!(strtrim = ft_strtrim(s1, "te")))
//         printf("NULL");
//     else
//         printf("%s\n",strtrim);
//     if (strtrim == s1)
//         printf("\nA new string was not returned\n");
// 	return (0);
// }
