/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/07 15:43:16 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void	put_pixels(t_map_data **map_data, mlx_image_t **img);
static void	bresenham(t_bresenham_coord coord, t_map_data **map_data,
				mlx_image_t **img);

void	input_to_screen(t_map_data **map_data)
{
	mlx_t		*mlx_start;
	mlx_image_t	*img;

	mlx_start = mlx_init(IMG_WIDTH, IMG_HEIGHT, "Fdf", true);
	if (mlx_start == NULL)
	{
		destroy_map_data((*map_data)->map, map_data);
		print_error_msg(MLX_INIT_FAILURE);
	}
	img = mlx_new_image(mlx_start, IMG_WIDTH, IMG_HEIGHT);
	if (img == NULL || (mlx_image_to_window(mlx_start, img, 0, 0) < 0))
	{
		destroy_map_data((*map_data)->map, map_data);
		print_error_msg(MLX_INIT_FAILURE);
	}
	put_pixels(map_data, &img);
	mlx_loop(mlx_start);
	mlx_terminate(mlx_start);
	destroy_map_data((*map_data)->map, map_data);
}

static void	put_pixels(t_map_data **map_data, mlx_image_t **img)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (y < (*map_data)->height)
	{
		if (x < (*map_data)->width - 1)
			bresenham(point_data(x, x + 1, y, y), map_data, img);
		if (y < (*map_data)->height - 1)
			bresenham(point_data(x, x, y, y + 1), map_data, img);
		if ((*map_data)->map[y][x].end_of_row == true)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}

static void	bresenham(t_bresenham_coord coord, t_map_data **map_data,
		mlx_image_t **img)
{
	float	x_increase;
	float	y_increase;

	(void)map_data;
	coord = zoom_multiplier(coord, map_data);
	x_increase = calculate_increase(coord.delta_x, coord.delta_x,
			coord.delta_y);
	y_increase = calculate_increase(coord.delta_y, coord.delta_x,
			coord.delta_y);
	while (coord.x - coord.x_next != 0 || coord.y - coord.y_next != 0)
	{
		mlx_put_pixel(*img, coord.x, coord.y, get_rgba(255, 255, 255, 255));
		coord.x += x_increase;
		coord.y += y_increase;
	}
}
