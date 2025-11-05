/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuzmin <akuzmin@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 07:54:10 by akuzmin           #+#    #+#             */
/*   Updated: 2025/11/04 18:46:02 by akuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_int_rgb(const t_rgb *color)
{
    if (!color)
        return (perror("create_int_rgb: null color pointer"), -1);
    if ((color->r < 0 || color->r > 255)
        || (color->g < 0 || color->g > 255)
        || (color->b < 0 || color->b > 255))
    {
        return (perror("create_int_rgb: color value out of range"), -1);
    }
    return ((color->r << 16) | (color->g << 8) | (color->b));
}

