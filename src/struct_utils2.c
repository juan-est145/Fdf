/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:46 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/15 17:39:08 by juestrel         ###   ########.fr       */
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
	unsigned int	zoom;
	unsigned int	map_coord_smallest;

	zoom = 0;
	map_coord_smallest = 0;
	if ((*map_data)->height < (*map_data)->width)
		map_coord_smallest = (*map_data)->width;
	else
		map_coord_smallest = (*map_data)->height;
	while ((map_coord_smallest) * zoom < IMG_HEIGHT - (IMG_HEIGHT / 2))
		zoom++;
	if (zoom != 0)
		zoom -= 1;
	coord.x *= zoom; //Change 10 for zoom later in all cases
	coord.x_next *= zoom;
	coord.y *= zoom;
	coord.y_next *= zoom;
	(*map_data)->zoom = zoom;
	return (coord);
}
