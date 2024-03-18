/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:49:57 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/18 13:34:34 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "fdf.h"

static int			get_zoom(t_map_data **map_data, int zoom);
static int			get_max_y_value(t_map_data **map_data, int *coord_x,
						int *coord_y, int *coord_z);
static int			get_max_y_value(t_map_data **map_data, int *coord_x,
						int *coord_y, int *coord_z);
static void			map_too_high(t_map_data **map_data);

t_bresenham_coord	zoom_multiplier(t_bresenham_coord coord,
		t_map_data **map_data)
{
	static int	zoom = 1;
	static bool	calculated_already = false;

	if (calculated_already == false)
	{
		zoom = get_zoom(map_data, zoom);
		calculated_already = true;
	}
	coord.x *= zoom;
	coord.x_next *= zoom;
	coord.y *= zoom;
	coord.y_next *= zoom;
	(*map_data)->zoom = zoom;
	return (coord);
}

static int	get_zoom(t_map_data **map_data, int zoom)
{
	int	coords[3];
	int	max_y_value;

	max_y_value = get_max_y_value(map_data, &coords[0], &coords[1], &coords[2]);
	while (max_y_value < (CEILING_VALUE))
	{
		max_y_value = ((coords[0] * zoom) + (coords[1] * zoom)) * sin(0.523599)
			- (coords[2] * zoom);
		zoom++;
	}
	if (zoom != 0)
	{
		zoom = (zoom - 2) - (zoom / 2);
		if (zoom < 1)
			zoom = 1;
	}
	else
		map_too_high(map_data);
	return (zoom);
}

static int	get_max_y_value(t_map_data **map_data, int *coord_x, int *coord_y,
		int *coord_z)
{
	unsigned int	x;
	unsigned int	y;
	int				max_y_value;

	y = 0;
	max_y_value = 0;
	while (y < (*map_data)->height)
	{
		x = 0;
		while (x < (*map_data)->width)
		{
			if ((x + y) * sin(0.523599)
				- (*map_data)->map[y][x].value_of_z > max_y_value)
			{
				max_y_value = (x + y) * sin(0.523599)
					- (*map_data)->map[y][x].value_of_z;
				*coord_x = x;
				*coord_y = y;
				*coord_z = (*map_data)->map[y][x].value_of_z;
			}
			x++;
		}
		y++;
	}
	return (max_y_value);
}

static void	map_too_high(t_map_data **map_data)
{
	destroy_map_data((*map_data)->map, map_data);
	mlx_terminate((*map_data)->mlx_start);
	print_error_msg(TOO_MUCH_HEIGHT);
}
