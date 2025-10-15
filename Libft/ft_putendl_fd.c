/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:39:31 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/07 07:54:09 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		write(fd, &s[i], 1);
	}
	write(fd, "\n", 1);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("\n///////////////\nexpected: lorem ipsum dolor sit amet$\n");
// 	ft_putendl_fd("lorem ipsum dolor sit amet", 2);
// 	printf("\n///////////////\nexpected:  lorem\nipsum\rdolor\tsit amet  $\n");
// 	ft_putendl_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
// 	printf("\n///////////////\nexpected: lorem ipsum do$\n");
// 	ft_putendl_fd("lorem ipsum do\0lor sit amet", 1);
// 	return (0);
// }
