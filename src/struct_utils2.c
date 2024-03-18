/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:46 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/18 13:34:34 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
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
