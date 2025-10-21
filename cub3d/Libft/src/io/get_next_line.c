/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:43:03 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/21 11:38:37 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

char	*sx_free(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

/**
 *	Read file with current file descriptor, while do not meat char '\n'
 *	When it is apears return string, which was joined with all sub strings
 *	readed by th length of buffer size
 */
static char	*readline(int fd, char *output)
{
	ssize_t	bytes_read;
	char	*vault;

	bytes_read = 1;
	vault = malloc(BUFFER_SIZE + 1);
	if (!vault)
		return (sx_free(&output));
	while (bytes_read > 0 && !gnl_strchr(output))
	{
		bytes_read = read(fd, vault, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			vault[bytes_read] = '\0';
			output = gnl_strjoin(output, vault);
			if (!output)
				return (sx_free(&vault));
		}
	}
	sx_free(&vault);
	if (bytes_read == -1)
		return (sx_free(&output));
	return (output);
}

static char	*write_line(char **buffer)
{
	char	*output;
	char	*temp_buffer;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	if (gnl_strchr(*buffer) != NULL)
		len = gnl_strchr(*buffer) - *buffer;
	else
		len = gnl_strlen(*buffer);
	output = gnl_substr(*buffer, 0, len);
	if (!output)
		return (sx_free(buffer));
	if (gnl_strchr(*buffer))
		temp_buffer = gnl_strdup(gnl_strchr(*buffer));
	else
		temp_buffer = NULL;
	sx_free(buffer);
	*buffer = temp_buffer;
	return (output);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!gnl_strchr(buffer[fd]) || !buffer[fd])
		buffer[fd] = readline(fd, buffer[fd]);
	if (gnl_strlen(buffer[fd]) == 0 || buffer[fd] == NULL)
		return (sx_free(&buffer[fd]));
	line = write_line(&buffer[fd]);
	if (!line)
		return (sx_free(&buffer[fd]));
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void	open_all(char *str)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open(str, O_RDONLY);
	printf("Its opened at fd: %d\n", fd);
	if (fd == -1)
		return ;
	
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	
	if (fd != 0)
		close(fd);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char way_to_test[50];
	
	snprintf(way_to_test, sizeof(way_to_test), "%s", av[1]);
	printf("\nTest\n");
	open_all(way_to_test);	
	
	return (0);
}
*/
