/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:48:36 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/11 01:09:51 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* STD + MLX INCLUDES ***************************************************** */

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/time.h>
/* ************************************************************************ */

/* LIBFT INCLUDES ********************************************************* */

# include "../Libft/include/get_next_line.h"
# include "../Libft/include/ft_printf.h"
# include "../Libft/include/libft.h"
/* ************************************************************************ */

/* GAME SETTINGS ********************************************************** */

// ~30 FPS -> 33333 for ~60 FPS -> 16666
# define FRAME_INTERVAL	16666 
# define MOVE_SPEED		0.1f
# define ROTATION_SPEED	0.01f
# define FLOOR			0
# define WALL			1
# define DEF_WIN_HEIGHT	960
# define DEF_WIN_WIDTH	1280
# define IMG_SIZE		10
/* ************************************************************************ */

/* KEYBOAR KEYS *********************************************************** */

# define L_ARROW		65361
# define R_ARROW		65363
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_EXIT		65307
/* ************************************************************************ */

/* MAP CHARS ************************************************************** */

# define SOUTH			"S"
# define WEST			"W"
# define EAST			"E"
# define NORTH			"N"
# define NORTH_TEXTURE	"NO"
# define SOUTH_TEXTURE	"SO"
# define WEST_TEXTURE	"WE"
# define EAST_TEXTURE	"EA"
# define FLOOR_COLOR		"F"
# define CEILING_COLOR	"C"
/* ************************************************************************ */

/* STRUCTS DEFINE ********************************************************* */

/**
 * @brief enum for easiest way to convert values.
 * @param [' ', '0', '1', 'Player'] --> [-1, 0, 1, 2]
 */
typedef enum e_cell
{
	CELL_VOID = -1,
	CELL_FLOOR = 0,
	CELL_WALL = 1,
	CELL_PLAYER = 2,
}	t_cell;

/**
 * @brief Simple Struct to store position date as x & y
 */
typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

/**
 * @brief Used in dfs algorithm. Mostly for check is border closed or not.
 */
typedef struct s_dfs
{
	char	**visited;
	t_pos	find;
}	t_dfs;

/**
 * @brief 
 */
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_image;

/**
 * @brief Graphics structure. Stores MLX things and textures.
 */
typedef struct s_graphics
{
	void	*mlx;
	void	*window;
	int		floor_color;
	int		ceiling_color;
	t_image	north;
	t_image	south;
	t_image	east;
	t_image	west;
	t_image	buffer;
}	t_graphics;

/**
 * @brief Hold inside Grid of map and maximal height and width.
 * [' ', '0', '1', 'Player'] --> [-1, 0, 1, 2]
 */
typedef struct s_map
{
	int		**matrix;
	int		map_width;
	int		map_height;
}	t_map;

/**
 * @brief Keep trach of keys for moovement which were pressed.
 * 
 * Also should be added rotation here.
 */
typedef struct s_controls
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
}	t_controls;

/**
 * @brief Consist basic data about player as:
 * @param pos - Position
 * @param dir - Direction;
 * @param palne - vector perpendicular to camera dir
 * @param controls - hold info about key pressed and released;
 * @param last_update_time - snapshot of time when its was updated
 */
typedef struct s_player
{
	t_pos		pos;
	t_pos		dir;
	t_pos		plane;
	t_controls	controls;
	long long	last_update_time;
}	t_player;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

/**
 * @brief RENDER INPUT
 * Render expect this structure from parser 
 */
typedef struct s_parsed_data
{
	t_rgb	*floor;	
	t_rgb	*ceiling;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*east_texture_path;
	char	*west_texture_path;
	char	**map_grid;
}	t_parsed_data;

/**
 * @brief Main STRUCTURE
 * @param data of structure `t_parsed_data`
 * @param graphics of structure `t_graphics`
 * @param map of structure `t_map`
 * @param player of structure `t_player`
 * @param error of structure `t_error_data` - may be will be depricated
 */
typedef struct s_game
{
	t_parsed_data	data;
	t_graphics		graphics;
	t_map			map;
	t_player		player;
}	t_game;
/* ************************************************************************ */

#endif
