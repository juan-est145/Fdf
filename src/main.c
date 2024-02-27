/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:36 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/27 18:55:18 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

/*void	ft_leaks(void)
{
	system("leaks -q fdf");
}
atexit(ft_leaks);*/

static bool			ft_parse_url(char *url);
static unsigned int	get_width(t_coord **coord);

int	main(int argc, char *argv[])
{
	t_coord		**coord;
	t_map_data	*map_data;

	coord = NULL;
	if (argc != 2)
		print_error_msg(INVALID_ARGC);
	if (ft_parse_url(argv[1]) == false)
		print_error_msg(INVALID_FILE_EXTENSION);
	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (map_data == NULL)
	{
		free(map_data);
		print_error_msg(MALLOC_ERROR);
	}
	map_data->height = load_matrix(argv[1], &map_data, &coord);
	map_data->map = coord;
	map_data->width = get_width(map_data->map);
	input_to_screen(&map_data);
	return (0);
}

static bool	ft_parse_url(char *url)
{
	const char	*extension;

	extension = ft_strrchr(url, '.');
	if (extension == NULL || ft_strncmp(extension, ".fdf", 4) != 0
		|| extension[4] != '\0')
		return (false);
	return (true);
}

static unsigned int	get_width(t_coord **coord)
{
	unsigned int	x;

	x = 0;
	while (coord[0][x].end_of_row != true)
		x++;
	return (x + 1);
}

// static void	second_tester(t_map_data *map_data); // Erase later
/*static void	second_tester(t_map_data *map_data)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	x = 0;
	while (y < map_data->height)
	{
		ft_printf("%i", map_data->map[y][x].value_of_z);
		ft_printf(" ");
		if (map_data->map[y][x].end_of_row == true)
		{
			x = 0;
			y++;
			ft_printf("\n");
		}
		else
			x++;
	}
}*/

/*(void)argc;
(void)argv;
	mlx_t	*mlx_start;
	mlx_image_t *img;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
		//Esto hace que la pantalla se vuelva completa
	mlx_start = mlx_init(512, 512, "FDF", true);
		//Crea la instancia que lleva el programa
	img = mlx_new_image(mlx_start, 250, 250); //Crea una nueva imagen
	mlx_image_to_window(mlx_start, img, 0, 0); //Cárgala a la ventana la imagen
	for (size_t x = 0; x < img->width; x++)
	{
		for (size_t y = 0; y < img->height; y++)
		{
			mlx_put_pixel(img, x, y, get_rgba(255, 0, 0, 255));
				//Con este bucle pintamos cada uno de los píxeles de la imagen
		}
	}
	mlx_loop(mlx_start); //Arranca el bucle de la pantalla
	mlx_terminate(mlx_start); // Cierra todo cuando se hace click en cerrar*/
