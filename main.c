/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:36 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/23 17:57:37 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

/*void	ft_leaks(void)
{
	system("leaks -q fdf");
}
atexit(ft_leaks);*/

static bool	ft_parse_url(char *url);

int	main(int argc, char *argv[])
{
	if (argc != 2)
		print_error_msg(INVALID_ARGC);
	if (ft_parse_url(argv[1]) == false)
		print_error_msg(INVALID_FILE_EXTENSION);
	load_matrix(argv[1]);
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

/*mlx_t	*mlx_start;
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
