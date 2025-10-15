/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 09:43:55 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 07:54:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strdup(char *src)
{
	char	*copy;
	int		length;
	int		i;

	length = 0;
	while (src[length])
		length++;
	copy = malloc((length + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < length)
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*out;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	out = malloc(len + 1);
	if (!out)
		return (sx_free(&out));
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		out[i] = s[i + start];
		i++;
	}
	out[len] = '\0';
	return (out);
}

char	*gnl_strchr(const char *s)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n')
		{
			s++;
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;
	size_t	i;
	size_t	j;

	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < len2)
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}
