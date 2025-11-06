/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkramer <lkramer@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 02:19:21 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:46:14 by lkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* **************************************************************************** */

# include "defines.h"
# include "colors.h"

/* **************************************************************************** */

/* FAIL/ERROR/SUCCESS OUTPUT TEMPLATE ***************************************** */

# define PRINT_FAIL(msg) \
	ft_printf("%s%s FAIL %s%s %s %s\n", BG_RED, WHITE, RESET, RED, msg, RESET)

# define PRINT_ERROR(msg) \
	ft_printf("%s%s ERROR %s%s %s %s\n", BG_RED, WHITE, RESET, RED, msg, RESET)

# define PRINT_SUCCESS(msg) \
	ft_printf("%s%s SUCCESS %s%s %s %s\n", BG_GREEN, BLACK, RESET, GREEN, msg, RESET)
/* **************************************************************************** */

/* t_pos ********************************************************************** */
void	tpos_sub(t_pos *data, float x, float y);
void	tpos_add(t_pos *data, float x, float y);
t_pos	init_tpos(void);
t_pos	tpos(float x, float y);
/* **************************************************************************** */

/* GET NEXT LINE ************************************************************** */

char	*get_next_line(int fd);
/* **************************************************************************** */

/* TESTS ********************************************************************** */

int		testing(void);
/* **************************************************************************** */



// Logic
int		close_game(void *param);

void	check_map_extension(char *map);

int		init_graphics(t_game *game);


void	check_border(t_game *game);

int	dfs(t_game game, int x, int y, t_dfs *data);


void	check_accessibility(t_game *game);

int		init_data(t_game *game, char *map_addr);

int		ft_error(t_game *game, int status_code);

void	move_player(t_game *game, int dx, int dy);


/* INPUTS ******************************************************************** */

void	rotate_player(t_game *game, int dir);
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
void	free_matrix(int **matrix, int height);
void	free_dfs_visited(t_dfs *data, int rows);

/* ************************** Initialization ******************************** */

void	init_player_data(t_game *game, char player_char, t_pos pos);

int		count_lines(char **lines, int start_idx);
int		**convert_map_to_matrix(char **map_grid, int height, int width);

int	parse_texture_path(t_game *game, char *path_str, char *texture_type);
int	parse_color_path(t_game *game, char *color_str, char *color_type);

/* **************************************************************************** */

/* CLEAN UP ******************************************************************* */

void	cleanup_graphics(t_game *game);
void	s_free(t_game *game);
void	c_free(t_rgb *color);
/* **************************************************************************** */

void	display_game(t_game *game);


#endif
