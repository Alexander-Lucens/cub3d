/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:28:00 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/10 15:09:20 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	extra_helper(int *out, char *data, int length)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	if (data[i] == '+' || data[i] == '-')
	{
		if (data[i] == '-')
			sign = -1;
		i++;
	}
	while (i < length || i == 1)
	{
		if (data[i] >= '0' && data[i] <= '9')
			*out = *out * 10 + (data[i++] - '0');
		else
			return (0);
	}
	*out = *out * sign;
	return (1);
}

/**
 * @brief Try to convert str to ins and save its length,
 * its trims
 * @param out - value to write output 
 * @param str - std to get data
 * @return int as true -on succes  and false on fail
 */
int	ft_atoi_extra(int *out, const char *str)
{
	int		length;
	char	*data;
	int		ret;

	*out = 0;
	data = ft_strtrim(str, "\t\n\v\f\r ");
	length = ft_strlen(data);
	if (length == 0)
		return (free(data), 0);
	ret = extra_helper(out, data, length);
	return (free(data), ret);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	out;
	int	i;

	sign = 1;
	out = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out * sign);
}
