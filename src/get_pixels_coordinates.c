/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixels_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:30:55 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/15 17:08:15 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void isometric_projection_pixel(t_coord **coord, unsigned int x, unsigned int y);

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
            printf("%i|%i", (*map_data)->map[y][x].pixel_x, (*map_data)->map[y][x].pixel_y);
            printf("\n");
            x++;
        }
        y++;
    }
    exit(0);
}

static void isometric_projection_pixel(t_coord **coord, unsigned int x, unsigned int y)
{
    int pixelx;
    int pixely;
    pixelx = coord[y][x].pixel_x = ((int)((x + 1) - (y + 1))) * cos(0.523599);
    pixely = coord[y][x].pixel_y = ((int)((x + 1) + (y + 1))) * sin(0.523599) - coord[y][x].value_of_z;
    (void)pixelx;
    (void)pixely;
}
