/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:41:27 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/26 18:44:09 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

void	input_to_screen(t_map_data **map_data)
{
	mlx_t		*mlx_start;
	mlx_image_t	*img;

	(void)img;
	mlx_start = mlx_init(1920, 1080, "Fdf", true);
	if (mlx_start == NULL)
	{
		destroy_map_data((*map_data)->map, map_data);
		print_error_msg(MLX_INIT_FAILURE);
	}
	img = mlx_new_image(mlx_start, 1920, 1080);
	mlx_loop(mlx_start);
	mlx_terminate(mlx_start);
	destroy_map_data((*map_data)->map, map_data);
}
