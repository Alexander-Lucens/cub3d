/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:15 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n || (n == 0 && len == 0))
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus = 0;
	len = num_len(n);
	if (n < 0)
	{
		n = -n;
		minus = 1;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (minus)
		str[0] = '-';
	return (str);
}
/*
int main(void)
{
	char *res;
	res = ft_itoa(0);
    printf("expected: 0 got: %s, end: %d\n", res, res[1]);
    free(res);
	res = ft_itoa(-9);
    printf("expected: -9 got: %s, end: %d\n", res, res[2]);
    free(res);
	res = ft_itoa(9);
    printf("expected: 9 got: %s, end: %d\n", res, res[1]);
    free(res);
	res = ft_itoa(10);
	printf("expected: 10 got: %s, end: %d\n", res, res[2]);
    free(res);
	res = ft_itoa(-10);
	printf("expected: -10 got: %s, end: %d\n", res, res[3]);
    free(res);
	res = ft_itoa(-5859);
    printf("expected: -5859 got: %s, end: %d\n", res, res[5]);
    free(res);
	res = ft_itoa(8124);
    printf("expected: 8124 got: %s, end: %d\n", res, res[4]);
    free(res);
	return (0);
}
*/
