/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/27 19:15:40 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void	put_pixels(t_map_data **map_data, mlx_image_t **img);

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
	unsigned int	y;
	unsigned int	x;
	unsigned int	x_offset;
	unsigned int	y_offset;

	y = 0;
	x_offset = (*img)->width / (*map_data)->width;
	y_offset = (*img)->height / (*map_data)->height;
	while (y < (*map_data)->height)
	{
		if ((*map_data)->map[y][x].color_present == false)
			mlx_put_pixel(*img, x * x_offset, y * y_offset, get_rgba(255, 255, 255, 255 * 3));
		else if ((*map_data)->map[y][x].color_present == true)
			mlx_put_pixel(*img, x * x_offset, y * y_offset, (*map_data)->map[y][x].color);
		if ((*map_data)->map[y][x].end_of_row == true)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}
