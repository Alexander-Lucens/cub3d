/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 11:37:26 by lkramer          ###   ########.fr       */
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
/*
#include <stdlib.h>
#include <stdio.h>

void substr_single_tester(int test_number, char *str, \
unsigned int start, size_t len)
{
	char	*strsub;
	long long l = len;
	strsub = ft_substr(str, start, len);
	printf("\nTest %d\nft_substr(%s, %d, %lld) pointer: %p\n", test_number,\
	str, start, l, str);
	printf("Output data: %s\nOutout pointer: %p", strsub, strsub);
}

int		main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	substr_single_tester(1, str, 0, 10);
	substr_single_tester(2, str, 7, 10);
	substr_single_tester(3, str, 7, 0);
	substr_single_tester(4, str, 0, 0);
	substr_single_tester(5, str, 400, 20);
	//substr_single_tester(6, "hola", 0, 18446744073709551615);
	
	return (0);
}
*/
