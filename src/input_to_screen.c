/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/06 20:27:36 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void	put_pixels(t_map_data **map_data, mlx_image_t **img);
static void	bresenham(t_bresenham_coord coord, t_map_data **map_data, mlx_image_t **img);

void	input_to_screen(t_map_data **map_data)
{
	mlx_t		*mlx_start;
	mlx_image_t	*img;

	mlx_start = mlx_init(1920, 1080, "Fdf", true);
	if (mlx_start == NULL)
	{
		destroy_map_data((*map_data)->map, map_data);
		print_error_msg(MLX_INIT_FAILURE);
	}
	img = mlx_new_image(mlx_start, 1920, 1080);
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
	t_bresenham_coord	bresenham_s;

	bresenham_s.x = 0;
	bresenham_s.y = 0;
	bresenham_s.x_next = bresenham_s.x + 1;
	bresenham_s.y_next = bresenham_s.y + 1;
	while (bresenham_s.y < (*map_data)->height)
	{
		bresenham(bresenham_s, map_data, img);
		if ((*map_data)->map[bresenham_s.y][bresenham_s.x].end_of_row == true)
		{
			bresenham_s.x = 0;
			bresenham_s.x_next = bresenham_s.x + 1;
			bresenham_s.y++;
			bresenham_s.y_next = bresenham_s.y + 1;
		}
		else
		{
			bresenham_s.x++;
			bresenham_s.x_next = bresenham_s.x + 1;
		}		
	}
}

static void	bresenham(t_bresenham_coord coord, t_map_data **map_data, mlx_image_t **img)
{
	float	x_increase;
	float	y_increase;
	
	(void)map_data;
	coord.x *= ZOOM;
	coord.y *= ZOOM;
	coord.x_next *= ZOOM;
	coord.y_next *= ZOOM;
	coord.delta_x = /*abs*/(coord.x_next - coord.x);
	coord.delta_y = /*abs*/(coord.y_next - coord.y);
	x_increase = calculate_increase(coord.delta_x, coord.delta_x, coord.delta_y);
	y_increase = calculate_increase(coord.delta_y, coord.delta_x, coord.delta_y);
	while (coord.x - coord.x_next != 0 || coord.y - coord.y_next != 0)
	{
		mlx_put_pixel(*img, coord.x, coord.y, 0xffffff);
		coord.x += x_increase;
		coord.y += y_increase;
	}
	
}
