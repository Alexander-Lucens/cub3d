#ifndef MOCKDATA_H
# define MOCKDATA_H

#include "../../includes/cub3d.h"

# define MAP_0_WIDTH 16 // 15 - if we dont count \0
# define MAP_0_HEIGHT 13 // 12 - if we dont count NULL determination

# define MAP_1_WIDTH 12 // 11 - if we dont count \0
# define MAP_1_HEIGHT 7 // 6 - if we dont count NULL determination

# define MAP_2_WIDTH 34 // 33 - if we dont count \0
# define MAP_2_HEIGHT 15 // 14 - if we dont count NULL determination


t_map	*mock_create_map0(void);

t_map	*mock_create_map1(void);

t_map	*mock_create_map2(void);



#endif