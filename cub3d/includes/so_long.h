/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:08 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/20 15:24:47 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

#define MOVE_DELAY 1000

# define FLOOR 0
# define WALL 1
# define SOUTH "S"
# define WEST "W"
# define EAST "E"
# define NORTH "N"
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define WEST_TEXTURE "WE"
# define EAST_TEXTURE "EA"
# define FLOOR_COLOR "F"
# define CEILING_COLOR "C"

// COLOR


typedef struct s_pos
{
	float	x; // make float 
	float	y; // make float
}	t_pos;

// changed <visited> int ** --> char ** (saved *4)
typedef struct s_dfs
{
	char	**visited;
	t_pos	find;
}	t_dfs;

typedef struct s_graphics
{
	void	*mlx;
	void	*window;
	void	*floor;	
	void	*ceiling;
	void	*north_texture;
	void	*south_texture;
	void	*east_texture;
	void	*west_texture;
}	t_graphics;

// changed <matrix> int ** --> char ** (saved *4)
typedef struct s_map
{
	// char	*map; - 
	char	**matrix;
	// int		rows;
	// int		cols;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_player
{
	t_pos	position;
	t_pos 	direction;
	int		controls;
}	t_player;

typedef struct s_game
{
	t_graphics	graphics;
	t_map		map;
	int			moves;
	t_player	player;
}	t_game;



// t_pos
t_pos	init_tpos(int x, int y);

// GNL
char	*get_next_line(int fd);

// main
int		main(int ac, char **av);

// Logic
int		close_game(void *param);
void	check_map_extension(char *map, t_game *game);
void	init_graphics(t_game *game);
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

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		update(t_game *game);

void	display_game(t_game *game);
// void	safe_free(void *str);
void	s_free(t_game *game);

#endif
