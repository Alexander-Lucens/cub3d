/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/03 09:02:47 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* **************************************************************************** */

# include "defines.h"
# include "colors.h"

/* **************************************************************************** */


t_pos	init_tpos(int x, int y);

char	*get_next_line(int fd);


// int		main(int ac, char **av);

// Logic
int		close_game(void *param);

void	check_map_extension(char *map);

int		init_graphics(t_game *game);


void	map_str_to_matrix(t_game *game);

void	check_border(t_game *game);

int		dfs(t_game game, int x, int y, t_dfs *data);

void	clean_matrix(t_dfs *data, t_game game);

void	delete_matrix(t_dfs *data, t_game game);

void	check_accessability(t_game *game);

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
int		parse_elements(t_game *game, char *content);
int		parse_texture_path(t_game *game, char *path_str, char *texture_type);
int		parse_color_path(t_game *game, char *color_str, char *color_type);
int		init_data(t_game *game, char *map_address);
char	*read_file(int fd);
int		check_white_spaces_end_of_str(char **lines, int *i);
int		validate_all_data(t_game *game);
t_rgb	*create_rgb_color(int r, int g, int b);
void	free_split(char **split);

/* **************************************************************************** */

/* ****************************** Change ************************************** */

void	display_game(t_game *game);
void	s_free(t_game *game);
/* **************************************************************************** */


#endif
