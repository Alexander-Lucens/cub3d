/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:07:08 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 07:54:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
// 	int i = 0;
//     while (i <= 47)
//     {
//         printf("%d", ft_isprint(i));
//         i++;
//     }
// 	printf("\n");
// 	i = 0;
//     while (i <= 47)
//     {
//         printf("%d", isprint(i));
//         i++;
//     }
// 	printf("\n");
// 	i = 123;
//     while (i <= 127)
//     {
//         printf("%d", ft_isprint(i));
//         i++;
//     }
// 	printf("\n");
// 	i = 123;
//     while (i <= 127)
//     {
//         printf("%d", isprint(i));
//         i++;
//     }
// 	printf("\n");
// 	return (0);
// }
