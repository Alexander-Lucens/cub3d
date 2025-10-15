/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:08 by akuzmin           #+#    #+#             */
/*   Updated: 2025/04/17 16:56:02 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "../src/gnl/get_next_line.h"
# include "../Libft/ft_printf.h"
# include "../Libft/libft.h"

# define SEGMENT_SIZE 32

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_geo
{
	t_pos	position;
	t_pos	direction;
}	t_geo;

typedef struct s_dfs
{
	char	**visited;
	t_pos	find;
}	t_dfs;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*enemy_right[4];
	void	*enemy_left[4];
	void	*enemy_top[4];
	void	*enemy_bottom[4];
	void	*border;
	void	*exit;
	void	*coins;
	void	*background;
	void	*player_right[4];
	void	*player_left[4];
	void	*player_top[4];
	void	*player_bottom[4];
	int		sprites_counter; 
}	t_graphics;

typedef struct s_map
{
	char	*map;
	char	**matrix;
	int		rows;
	int		cols;
	int		coins_all;
	int		coins_left;
	int		count_enemies;
	int		window_width;
	int		window_height;
	t_geo	player;
	t_geo	exit;
	t_geo	*coins;
	t_geo	*enemies;
}	t_map;

typedef struct s_game
{
	t_graphics	graphics;
	t_map		map;
	int			moves;
	int			exit_status;
}	t_game;

// t_pos & t_geo
t_pos	init_tpos(int x, int y);
t_geo	init_tgeo(t_pos position, t_pos direction);

// GNL
char	*get_next_line(int fd);

// main
int		main(int ac, char **av);

// Logic of exit
int		close_game(void *param);

// Grafic initialisation
void	init_images(t_game *game, int size);
void	init_img_enemy1(t_game *game, int size);
void	init_img_enemy2(t_game *game, int size);
void	init_img_player1(t_game *game, int size);
void	init_img_player2(t_game *game, int size);

void	check_map_extension(char *map, t_game *game);
void	init_graphics(t_game *game);
void	show_info(t_game *game);

void	fill_enemies_position(t_game *game);
void	fill_coins_position(t_game *game);

void	map_str_to_matrix(t_game *game);
void	check_border(t_game *game);
int		dfs(t_game game, int x, int y, t_dfs *data);
void	clean_matrix(t_dfs *data, t_game game);
void	delete_matrix(t_dfs *data, t_game game);
void	check_accessability(t_game *game);
int		init_data(t_game *game, char *map_addr);
int		ft_error(t_game *game, int status_code);
void	move_player(t_game *game, int dx, int dy);
int		key_press(int keycode, void *param);
void	display_game(t_game *game);
void	s_free(t_game *game);

#endif
