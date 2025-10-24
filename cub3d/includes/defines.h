/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:48:36 by akuzmin           #+#    #+#             */
/*   Updated: 2025/10/24 07:15:25 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/* **************************************************************************** */

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

/* **************************************************************************** */

# include "../Libft/include/get_next_line.h"
# include "../Libft/include/ft_printf.h"
# include "../Libft/include/libft.h"

/* **************************************************************************** */

# define	SEGMENT_SIZE 10

# define	MOVE_DELAY 1000

/* **************************************************************************** */

# define	FLOOR			0
# define	WALL			1
# define	SOUTH			"S"
# define	WEST			"W"
# define	EAST			"E"
# define	NORTH			"N"


/* **************************************************************************** */

# define	LEFT_ARROW		65361
# define	RIGHT_ARROW		65363

# define	KEY_W(key)		((key) == 13 || (key) == 119)
# define	KEY_S(key)		((key) == 1	 || (key) == 115)
# define	KEY_A(key)		((key) == 0  || (key) == 97)
# define	KEY_D(key)		((key) == 2  || (key) == 100)
# define	KEY_EXIT(key)	((key) == 53 || (key) == 65307)


/* **************************************************************************** */

# define	NORTH_TEXTURE	"NO" // Let's see, but idk where it should be used
# define	SOUTH_TEXTURE	"SO"
# define	WEST_TEXTURE	"WE"
# define	EAST_TEXTURE	"EA"

# define	FLOOR_COLOR		"F"
# define	CEILING_COLOR	"C"

/* **************************************************************************** */

/**
 * @brief enum for easiest way to convert values.
 * 
 */
typedef enum e_cell
{
	CELL_VOID   = -1,  // ' ' - пустота (вне карты)
	CELL_FLOOR  = 0,   // '0' - пол, можно идти
	CELL_WALL   = 1,   // '1' - стена, нельзя пройти
	CELL_NORTH  = 2,   // 'N' - игрок смотрит на север
	CELL_SOUTH  = 3,   // 'S' - игрок смотрит на юг
	CELL_EAST   = 4,   // 'E' - игрок смотрит на восток
	CELL_WEST   = 5    // 'W' - игрок смотрит на запад
}	t_cell;

/* **************************************************************************** */

/**
 * @brief Simple Struct to store position date as x & y
 */
typedef struct s_pos
{
	float	x; // make float 
	float	y; // make float
}	t_pos;
/* **************************************************************************** */

/**
 * @brief Used in dfs algorithm. Mostly for check is border closed or not.
 * 
 */
typedef struct s_dfs
{
	char	**visited;
	t_pos	find;
}	t_dfs;
/* **************************************************************************** */

/**
 * @brief Graphics structure. Stores MLX things and textures.
 * 
 */
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
/* **************************************************************************** */

/**
 * @brief Hold inside Grid of map and maximal height and width.
 * [' ', '0', '1', 'N', 'S', 'E', 'W'] --> [-1, 0, 1, 2, 3, 4, 5]
 */
typedef struct s_map
{
	int		**matrix;
	int		map_width;
	int		map_height;
}	t_map;
/* **************************************************************************** */

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
}	t_controls;
/* **************************************************************************** */

/**
 * @brief Consist basic data about player as:
 * 1. Position;
 * 2. Direction;
 * controls - And keys wich were presed to move player(change position and direction);
 * delay - duration of delay from key press to action
 */
typedef struct s_player
{
	t_pos		position;
	t_pos		direction;
	t_controls	controls;
	int			delay;
}	t_player;
/* **************************************************************************** */

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

/**
 * @brief 
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
/* **************************************************************************** */

/**
 * @brief Main STRUCTURE
 * Here we storing all date about the game.
 * Could be also added some features later, if needed.
 */
typedef struct s_game
{
	t_parsed_data	data;
	t_graphics		graphics;
	t_map			map;
	t_player		player;
}	t_game;
/* **************************************************************************** */

#endif
