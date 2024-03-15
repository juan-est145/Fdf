/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/03/15 15:26:19 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static void	put_pixels(t_map_data **map_data, mlx_image_t **img);
static void	bresenham(t_bresenham_coord coord, t_map_data **map_data,
				mlx_image_t **img, int color);
static int	select_color(t_map_data **map_data, unsigned int x, unsigned int y);
static void	isometric_projection(t_bresenham_coord *coord,
				t_map_data **map_data);
static void slope_less_than_one(t_bresenham_coord coord, mlx_image_t **img, int color);
static void slope_bigger_than_one(t_bresenham_coord coord, mlx_image_t **img, int color);

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
	int				color;

	x = 0;
	y = 0;
	while (y < (*map_data)->height)
	{
		color = select_color(map_data, x, y);
		if (x < (*map_data)->width - 1)
			bresenham(point_data(x, x + 1, y, y), map_data, img, color);
		if (y < (*map_data)->height - 1)
			bresenham(point_data(x, x, y, y + 1), map_data, img, color);
		if ((*map_data)->map[y][x].end_of_row == true)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
}

static int	select_color(t_map_data **map_data, unsigned int x, unsigned int y)
{
	if ((*map_data)->map[y][x].color_present == true)
		return ((*map_data)->map[y][x].color);
	else
		return (get_rgba(255, 255, 255, 255));
}

static void	bresenham(t_bresenham_coord coord, t_map_data **map_data,
		mlx_image_t **img, int color)
{
	coord = zoom_multiplier(coord, map_data);
	isometric_projection(&coord, map_data);
	/*The commented lines below "solve" the problem of the split drawing, but it is not consistent*/
	coord.x += IMG_WIDTH/2;
	coord.x_next += IMG_WIDTH/2;
	coord.y += IMG_HEIGHT/2;
	coord.y_next += IMG_HEIGHT/2;
	coord.delta_x = (coord.x_next - coord.x);
	coord.delta_y = (coord.y_next - coord.y);
	if (fabsf(coord.delta_x) > fabsf(coord.delta_y))
		slope_less_than_one(coord, img, color);
	else
		slope_bigger_than_one(coord, img, color);
}

static void	isometric_projection(t_bresenham_coord *coord,
		t_map_data **map_data)
{
	unsigned int	tmp;
	int				z_value;
	int				z_next_value;

	z_value = (*map_data)->map[coord->map_y][coord->map_x].value_of_z;
	z_next_value = (*map_data)->map[coord->map_y_next][coord->map_x_next].value_of_z;
	z_value *= (*map_data)->zoom; //New change to see if it affects isometric
	z_next_value *= (*map_data)->zoom; //New change to see if it affects isometric
	tmp = coord->x;
	coord->x = (tmp - coord->y) * cos(0.523599);
	coord->y = (tmp + coord->y) * sin(0.523599) - z_value;
	tmp = coord->x_next;
	coord->x_next = (tmp - coord->y_next) * cos(0.523599);
	coord->y_next = (tmp + coord->y_next) * sin(0.523599) - z_next_value;

	//One of the problems I seem to have is that I do not add a zoom to the z value before doing the isometric
	//projection
}

static void slope_less_than_one(t_bresenham_coord coord, mlx_image_t **img, int color)
{
	int p;
	int i;

	i = -1;
	p = 2 * fabsf(coord.delta_y) - fabsf(coord.delta_x);
	mlx_put_pixel(*img, coord.x, coord.y, color);
	while (++i < fabsf(coord.delta_x))
	{
		if (coord.delta_x > 0)
			coord.x += 1;
		else
			coord.x -= 1;
		if (p < 0)
			p = p + 2 * fabsf(coord.delta_y);
		else
		{
			if (coord.delta_y > 0)
				coord.y += 1;
			else
				coord.y -= 1;
			p = p + 2 * fabsf(coord.delta_y) - 2 * fabsf(coord.delta_x);
		}
		mlx_put_pixel(*img, coord.x, coord.y, color);
	}
}

static void slope_bigger_than_one(t_bresenham_coord coord, mlx_image_t **img, int color)
{
	int p;
	int i;

	i = -1;
	p = 2 * fabsf(coord.delta_x) - fabsf(coord.delta_y);
	mlx_put_pixel(*img, coord.x, coord.y, color);
	while (++i < fabsf(coord.delta_y))
	{
		if (coord.delta_y > 0)
  			coord.y += 1;
		else
			coord.y -= 1;
		if (p < 0)
		p = p + 2 * fabsf(coord.delta_x);
		else
		{
			if (coord.delta_x > 0)
				coord.x += 1;
			else
				coord.x -= 1;
			p = p + 2 * fabsf(coord.delta_x) - 2 * fabsf(coord.delta_y);
		}
		mlx_put_pixel(*img, coord.x, coord.y, color);
	}
}
