/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:46 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/07 14:47:45 by juestrel         ###   ########.fr       */
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

float	calculate_increase(float delta, unsigned int x_delta,
		unsigned int y_delta)
{
	if (x_delta > y_delta)
		return (delta / x_delta);
	else
		return (delta / y_delta);
}

t_bresenham_coord	point_data(unsigned int x0, unsigned int x1,
		unsigned int y0, unsigned int y1)
{
	t_bresenham_coord	data;

	data.x = x0;
	data.x_next = x1;
	data.y = y0;
	data.y_next = y1;
	data.delta_x = (data.x_next - data.x);
	data.delta_y = (data.y_next - data.y);
	return (data);
}

t_bresenham_coord	zoom_multplier(t_bresenham_coord coord,
		t_map_data **map_data)
{
	unsigned int	zoom_height;
	unsigned int	zoom_width;

	zoom_height = 0;
	zoom_width = 0;
	while (((*map_data)->height) * zoom_height < IMG_HEIGHT)
		zoom_height++;
	if (zoom_height != 0)
		zoom_height -= 1;
	while (((*map_data)->width) * zoom_width < IMG_HEIGHT)
		zoom_width++;
	if (zoom_width != 0)
		zoom_width -= 1;
	coord.x *= zoom_width;
	coord.x_next *= zoom_width;
	coord.y *= zoom_height;
	coord.y_next *= zoom_height;
	coord.delta_x = (coord.x_next - coord.x);
	coord.delta_y = (coord.y_next - coord.y);
	return (coord);
}
