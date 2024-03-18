/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:19:58 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/18 12:31:30 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void	isometric_projection(t_bresenham_coord *coord,
				t_map_data **map_data);
static void	slope_less_than_one(t_bresenham_coord coord, mlx_image_t **img,
				int color);
static void	slope_bigger_than_one(t_bresenham_coord coord, mlx_image_t **img,
				int color);

void	bresenham(t_bresenham_coord coord, t_map_data **map_data,
		mlx_image_t **img, int color)
{
	coord = zoom_multiplier(coord, map_data);
	isometric_projection(&coord, map_data);
	coord.x += IMG_WIDTH / 2;
	coord.x_next += IMG_WIDTH / 2;
	coord.y += IMG_HEIGHT / 2;
	coord.y_next += IMG_HEIGHT / 2;
	coord.delta_x = (coord.x_next - coord.x);
	coord.delta_y = (coord.y_next - coord.y);
	if (abs(coord.delta_x) > abs(coord.delta_y))
		slope_less_than_one(coord, img, color);
	else
		slope_bigger_than_one(coord, img, color);
}

static void	isometric_projection(t_bresenham_coord *coord,
		t_map_data **map_data)
{
	int	tmp;
	int	z_value;
	int	z_next_value;

	z_value = (*map_data)->map[coord->map_y][coord->map_x].value_of_z;
	z_next_value = \
	(*map_data)->map[coord->map_y_next][coord->map_x_next].value_of_z;
	z_value *= (*map_data)->zoom;
	z_next_value *= (*map_data)->zoom;
	tmp = coord->x;
	coord->x = (tmp - coord->y) * cos(0.523599);
	coord->y = (tmp + coord->y) * sin(0.523599) - z_value;
	tmp = coord->x_next;
	coord->x_next = (tmp - coord->y_next) * cos(0.523599);
	coord->y_next = (tmp + coord->y_next) * sin(0.523599) - z_next_value;
}

static void	slope_less_than_one(t_bresenham_coord coord, mlx_image_t **img,
		int color)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(coord.delta_y) - abs(coord.delta_x);
	mlx_put_pixel(*img, coord.x, coord.y, color);
	while (++i < abs(coord.delta_x))
	{
		if (coord.delta_x > 0)
			coord.x += 1;
		else
			coord.x -= 1;
		if (p < 0)
			p = p + 2 * abs(coord.delta_y);
		else
		{
			if (coord.delta_y > 0)
				coord.y += 1;
			else
				coord.y -= 1;
			p = p + 2 * abs(coord.delta_y) - 2 * abs(coord.delta_x);
		}
		mlx_put_pixel(*img, coord.x, coord.y, color);
	}
}

static void	slope_bigger_than_one(t_bresenham_coord coord, mlx_image_t **img,
		int color)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(coord.delta_x) - abs(coord.delta_y);
	mlx_put_pixel(*img, coord.x, coord.y, color);
	while (++i < abs(coord.delta_y))
	{
		if (coord.delta_y > 0)
			coord.y += 1;
		else
			coord.y -= 1;
		if (p < 0)
			p = p + 2 * abs(coord.delta_x);
		else
		{
			if (coord.delta_x > 0)
				coord.x += 1;
			else
				coord.x -= 1;
			p = p + 2 * abs(coord.delta_x) - 2 * abs(coord.delta_y);
		}
		mlx_put_pixel(*img, coord.x, coord.y, color);
	}
}
