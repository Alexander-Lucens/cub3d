/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 16:48:36 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**ft_free_all(char **list, size_t i)
{
	while (i > 0)
		free(list[--i]);
	free(list);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	size_t	i;
	char	**list;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	list = malloc(sizeof(char *) * (words + 1));
	if (!list)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		list[i] = malloc(ft_word_len(s, c) + 1);
		if (!list[i])
			return (ft_free_all(list, i));
		ft_strlcpy(list[i], s, ft_word_len(s, c) + 1);
		s += ft_word_len(s, c);
		i++;
	}
	list[i] = NULL;
	return (list);
}
