/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:46 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/17 19:37:18 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

void	malloc_error(t_map_line_read **head, t_coord **map,
		t_map_data **map_data)
{
	free_map_line(head);
	if (map != NULL)
		free(map);
	if (*map_data != NULL)
		free(*map_data);
	print_error_msg(MALLOC_ERROR);
}

void	destroy_map_data(t_coord **map, t_map_data **map_data)
{
	unsigned int	y;

	y = (**map_data).height;
	if (y > 0)
	{
		y -= 1;
		while (y != 0)
		{
			free(map[y]);
			y--;
		}
	}
	free(map[y]);
	if (map != NULL)
		free(map);
	if (*map_data != NULL)
		free(*map_data);
}

t_bresenham_coord	point_data(int x0, int x1, int y0, int y1)
{
	t_bresenham_coord	data;

	data.map_x = x0;
	data.map_y = y0;
	data.map_x_next = x1;
	data.map_y_next = y1;
	data.x = (float)x0;
	data.x_next = (float)x1;
	data.y = (float)y0;
	data.y_next = (float)y1;
	data.delta_x = (data.x_next - data.x);
	data.delta_y = (data.y_next - data.y);
	return (data);
}

t_bresenham_coord	zoom_multiplier(t_bresenham_coord coord,
		t_map_data **map_data)
{
	static int 	zoom = 1;
	unsigned int	x;
	unsigned int	y;
	int				max_y_value;
	int				coords[3];
	static bool			calculated_already = false;
	
	y = 0;
	max_y_value = 0;
	if (calculated_already == false)
	{
		calculated_already = true;
		while (y < (*map_data)->height)
		{
			x = 0;
			while (x < (*map_data)->width)
			{
				if ((x + y) * sin(0.523599) - (*map_data)->map[y][x].value_of_z > max_y_value)
				{
					max_y_value = (x + y) * sin(0.523599) - (*map_data)->map[y][x].value_of_z;
					coords[0] = x;
					coords[1] = y;
					coords[2] = (*map_data)->map[y][x].value_of_z;
				}
				x++;
			}
			y++;
		}
		while (max_y_value < (540/*IMG_HEIGHT / 2*/))
		{
			max_y_value = ((coords[0] * zoom) + (coords[1] * zoom)) * sin(0.523599) - (coords[2] * zoom);
			zoom++;
			/*if (max_y_value > (540))
				break;*/
		}
		if (zoom != 0) //Add condition to check that if zoom is equal to 0, send an error.
		{
			zoom = (zoom - 2) - (zoom/2);
			if (zoom < 1)
				zoom = 1;
		}
	}
	coord.x *= zoom;
	coord.x_next *= zoom;
	coord.y *= zoom;
	coord.y_next *= zoom;
	(*map_data)->zoom = zoom;
	return (coord);
}