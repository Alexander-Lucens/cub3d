/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/31 17:49:00 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* **************************************************************************** */

# include "defines.h"
# include "colors.h"

/* **************************************************************************** */

# define PRINT_FAIL(msg) \
	ft_printf("%s%s FAIL %s%s %s %s\n", BG_RED, WHITE, RESET, RED, msg, RESET)

# define PRINT_SUCCESS(msg) \
	ft_printf("%s%s SUCCESS %s%s %s %s\n", BG_GREEN, BLACK, RESET, GREEN, msg, RESET)

	
t_pos	init_tpos(int x, int y);

char	*get_next_line(int fd);


// int		main(int ac, char **av);

// Logic
int		close_game(void *param);
void	check_map_extension(char *map);
void	init_graphics(t_game *game);


void	check_border(t_game *game);

int	dfs(t_game game, int x, int y, t_dfs *data);


void	check_accessibility(t_game *game);

int		init_data(t_game *game, char *map_addr);

int		ft_error(t_game *game, int status_code);

void	move_player(t_game *game, int dx, int dy);


/* ************************** Remains the same ******************************** */

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		update(t_game *game);
/* **************************************************************************** */

/* ************************** Parser******************************** */

t_game	*parse_cub_file(t_game *game, char *map_address);
int		parse_texture_elements(t_game *game, char *content);
int		valid_map(t_game *game, char **map_grid);
int		parse_map_grid(t_game *game, char *content);
char	*read_file(int fd);
int		check_white_spaces_end_of_str(char **lines, int *i);
int		validate_all_data(t_game *game);
void	free_split(char **split);
void	free_dfs_visited(t_dfs *data, int rows);
int		count_lines(char **lines, int start_idx);

int	parse_texture_path(t_game *game, char *path_str, char *texture_type);
int	parse_color_path(t_game *game, char *color_str, char *color_type);



/* **************************************************************************** */

/* ****************************** Change ************************************** */

void	display_game(t_game *game);
void	s_free(t_game *game);
/* **************************************************************************** */


#endif
