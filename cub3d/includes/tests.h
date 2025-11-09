/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:48:36 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/09 17:16:07 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

/* INCLUDES *************************************************************** */

# include "cub3d.h"
/* ************************************************************************ */

/* MAP SIZING DEFINES ***************************************************** */

# define MAP_0_WIDTH 15
# define MAP_0_HEIGHT 12

# define MAP_1_WIDTH 11
# define MAP_1_HEIGHT 6

# define MAP_2_WIDTH 33
# define MAP_2_HEIGHT 14
/* ************************************************************************ */

/* TEST DATA STRUCT ******************************************************* */
typedef struct s_test_data
{
	t_parsed_data	*origin;
	t_parsed_data	*expect;
	int				width;
	int				height;
}	t_test_data;
/* ************************************************************************ */

/* parsed_data_init.c ***************************************************** */

t_rgb			*init_rgb(int r, int g, int b);
t_test_data		*init_test_struct(t_parsed_data *origin, t_parsed_data *expect,
					int width, int height);
/* ************************************************************************ */

/* parsed_data_utils.c **************************************************** */

int				validate_data_initialisation(t_test_data *data);
int				validate_colors(t_test_data *data);
int				validate_textures_path(t_test_data *data);
int				validate_map_grid(t_test_data *data);
int				parser_test_map(t_test_data *data);
void			test_data_free(t_parsed_data *data);
/* ************************************************************************ */

/* parsed_data_maps.c ***************************************************** */

t_parsed_data	*parsed_data_map0(void);
t_parsed_data	*parsed_data_map1(void);
t_parsed_data	*parsed_data_map2(void);
/* ************************************************************************ */

/* parsed_data_tests.c **************************************************** */
/* ************ Each test checks equality of expected data and parser data. */

int				parser_test_map0(t_parsed_data *origin);
int				parser_test_map1(t_parsed_data *origin);
int				parser_test_map2(t_parsed_data *origin);
int				test_valid_parse_texture_path(void);
int				test_invalid_parse_texture_path(void);
int				test_valid_parse_color(void);
int				test_invalid_parse_color(void);
int				test_valid_parse_cub_file(void);
int				test_valid1_parse_cub_file(void);
int				test_valid2_parse_cub_file(void);
/* ************************************************************************ */

/* validator.c ************************************************************ */

int				run_as_validator(t_parsed_data *(*func)(char *));
int				run_as_validator_game(t_game *(*func)(t_game *, char *));
/* ************************************************************************ */

#endif