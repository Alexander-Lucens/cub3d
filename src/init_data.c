/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/16 16:19:33 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_ordinarity_of_lines(t_game *game)
{
	int	row;
	int	i;

	i = -1;
	row = 0;
	while (game->map.map[++i] != '\0')
	{
		if (game->map.map[i] == '\n')
			row++;
		if (game->map.map[i] != '\n' && \
			(game->map.cols) * (row) + (row - 1) == i)
			ft_error(game, 102);
	}
}

static char	*read_file(t_game *game, int fd)
{
	char	*out;
	char	*temp;
	char	*line;

	line = get_next_line(fd);
	game->map.cols = ft_strlen(line) - 1;
	out = ft_strdup("");
	while (line != NULL)
	{
		game->map.rows++;
		temp = ft_strjoin(out, line);
		free(out);
		out = temp;
		free(line);
		line = get_next_line(fd);
	}
	return (out);
}

int	init_data(t_game *game, char *map_address)
{
	int		fd;

	game->map.rows = 0;
	game->moves = 0;
	check_map_extension(map_address, game);
	fd = open(map_address, O_RDONLY);
	if (fd == -1)
		ft_error(game, 100);
	game->map.map = read_file(game, fd);
	check_ordinarity_of_lines(game);
	if ((game->map.cols < 3 || game->map.rows < 3) && \
		game->map.cols + game->map.cols < 8)
		ft_error(game, 105);
	map_str_to_matrix(game);
	init_graphics(game);
	display_game(game);
	return (0);
}
