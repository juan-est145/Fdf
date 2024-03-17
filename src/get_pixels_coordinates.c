/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:30:55 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/17 14:12:30 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void isometric_projection_pixel(t_coord **coord, unsigned int x, unsigned int y);
static void find_offset(t_map_data **map_data);

void    get_pixels_coords(t_map_data **map_data)
{
    unsigned int    x;
    unsigned int    y;

    y = 0;
    while (y < (*map_data)->height)
    {
        x = 0;
        while (x < (*map_data)->width)
        {
            isometric_projection_pixel((*map_data)->map, x, y);
            x++;
        }
        y++;
    }
    find_offset(map_data);
}

static void isometric_projection_pixel(t_coord **coord, unsigned int x, unsigned int y)
{
    coord[y][x].pixel_x = ((int)x - (int)y) * cos(0.523599);
    coord[y][x].pixel_y = ((int)x + (int)y) * sin(0.523599) - coord[y][x].value_of_z;
}

static void find_offset(t_map_data **map_data)
{
    unsigned int    x;
    unsigned int    y;

    (*map_data)->x_offset = 0;
    (*map_data)->y_offset = 0;
    y = 0;
    while (y < (*map_data)->height)
    {
        x = 0;
        while (x < (*map_data)->width)
        {
            if ((*map_data)->map[y][x].pixel_x <  (*map_data)->x_offset)
                (*map_data)->x_offset = abs((*map_data)->map[y][x].pixel_x);
            if (((*map_data)->map[y][x].pixel_y <  (*map_data)->y_offset))
                (*map_data)->y_offset = abs((*map_data)->map[y][x].pixel_y);
            x++;
        }
        y++;
    }
}

