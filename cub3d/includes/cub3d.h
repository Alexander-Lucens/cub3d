/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 16:23:14 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* INCLUDES **************************************************************** */

# include "defines.h"
# include "colors.h"
/* ************************************************************************* */

/* FAIL/ERROR/SUCCESS OUTPUT TEMPLATE ************************************** */

int			PRINT_FAIL(char *msg);
int			PRINT_ERROR(char *msg);
int			PRINT_SUCCESS(char *msg);
/* ************************************************************************* */

/* t_pos ******************************************************************* */

void		tpos_sub(t_pos *data, float x, float y);
void		tpos_add(t_pos *data, float x, float y);
t_pos		init_tpos(void);
t_pos		tpos(float x, float y);
/* ************************************************************************* */

/* GET NEXT LINE *********************************************************** */

char		*get_next_line(int fd);
/* ************************************************************************* */

/* TESTS ******************************************************************* */

int			testing(void);
/* ************************************************************************* */

/* INPUTS ****************************************************************** */

int			is_invalid_move(t_game *game, t_pos new_pos);
void		rotate_player(t_game *game, int dir);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			update(t_game *game);
int			close_game(void *param);
/* ************************************************************************* */

/* PARSER ****************************************************************** */

int			check_map_extension(char *map);
void		check_border(t_game *game);
int			dfs(t_game game, int x, int y, t_dfs *data);
void		check_accessibility(t_game *game);

t_game		*parse_cub_file(t_game *game, char *map_address);
int			parse_texture_elements(t_game *game, char *content);
int			valid_map(t_game *game, char **map_grid);
int			parse_map_grid(t_game *game, char *content);
char		*read_file(int fd);
int			check_white_spaces_end_of_str(char **lines, int *i);
int			validate_all_data(t_game *game);
void		free_split(char **split);
void		free_matrix(int **matrix, int height);
void		free_dfs_visited(t_dfs *data, int rows);
/* ************************************************************************* */

/* INITS ******************************************************************* */

int			init_data(t_game *game, char *map_addr);
int			ft_error(t_game *game, char *msg);
int			create_int_rgb(const t_rgb *color);
int			init_buffer(t_game *game);
int			init_graphics(t_game *game);
void		init_player_data(t_game *game, char player_char, t_pos pos);
int			count_lines(char **lines, int start_idx);
int			**convert_map_to_matrix(char **map_grid, int height, int width);
int			parse_texture_path(t_game *game, char *path_str,
				char *texture_type);
int			parse_color_path(t_game *game, char *color_str, char *color_type);
/* ************************************************************************* */

/* CLEAN UP **************************************************************** */

void		cleanup_graphics(t_game *game);
void		s_free(t_game *game);
void		c_free(t_rgb *color);
/* ************************************************************************* */

/* RENDER ****************************************************************** */

void		put_pixel_to_buffer(t_image *buffer, int x, int y, int color);
int			get_texture_pixel(t_image *tex, int x, int y);
void		draw_floor_and_ceiling(t_game *game, int x, int draw_start);
void		display_game(t_game *game);
/* ************************************************************************* */

/* TIME UNITS ************************************************************** */

long long	get_time_in_us(void);
/* ************************************************************************* */

#endif
