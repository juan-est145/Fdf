/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:30:55 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/17 13:24:45 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void isometric_projection_pixel(t_coord **coord, unsigned int x, unsigned int y);
static void find_offset(t_map_data **map_data);
static void apply_offset(t_map_data **map_data, int x_offset, int y_offset);

void    get_pixels_coords(t_map_data **map_data)
{
    unsigned int    x;
    unsigned int    y;

    y = 0;
    while (y < (*map_data)->width)
    {
        x = 0;
        while (x < (*map_data)->height)
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
    int pixelx; //Erase later
    int pixely; //Erase later
    pixelx = coord[y][x].pixel_x = ((int)((x) - (y))) * cos(0.523599);
    pixely = coord[y][x].pixel_y = ((int)((x) + (y))) * sin(0.523599) - coord[y][x].value_of_z;
    (void)pixelx; //Erase later
    (void)pixely; //Erase later
}

static void find_offset(t_map_data **map_data)
{
    int biggest_x_negative;
    int biggest_y_negative;
    unsigned int    x;
    unsigned int    y;

    biggest_x_negative = 0;
    biggest_y_negative = 0;
    y = 0;
    while (y < (*map_data)->height)
    {
        x = 0;
        while (x < (*map_data)->width)
        {
            if ((*map_data)->map[y][x].pixel_x <  biggest_x_negative)
                biggest_x_negative = (*map_data)->map[y][x].pixel_x;
            if (((*map_data)->map[y][x].pixel_y <  biggest_y_negative))
                biggest_y_negative = (*map_data)->map[y][x].pixel_y;
            x++;
        }
        y++;
    }
    apply_offset(map_data, biggest_x_negative, biggest_y_negative);
}

static void apply_offset(t_map_data **map_data, int x_offset, int y_offset)
{
    unsigned int    x;
    unsigned int    y;
    
    y = 0;
    while (y < (*map_data)->height)
    {
        x = 0;
        while (x < (*map_data)->width)
        {
            (*map_data)->map[y][x].pixel_x += abs(x_offset);
            (*map_data)->map[y][x].pixel_y += abs(y_offset);
            x++;
        }
        y++;
    }
}
