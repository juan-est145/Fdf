/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:36 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/22 16:13:33 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -Wall -Werror -Wextra main.c ./MLX42/build/libmlx42.a -ldl
//-lglfw -I include -lglfw -L "/Users/juestrel/.brew/opt/glfw/lib/" -lm

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

/*void	ft_leaks(void)
{
	system("leaks -q a.out");
}
atexit(ft_leaks);*/

int	main(void)
{
	mlx_t	*mlx_start;
    mlx_image_t *img;

	mlx_set_setting(MLX_STRETCH_IMAGE, true); //Esto hace que la pantalla se vuelva completa
	mlx_start = mlx_init(512, 512, "FDF", true); //Crea la instancia que lleva el programa
    img = mlx_new_image(mlx_start, 250, 250); //Crea una nueva imagen
    mlx_image_to_window(mlx_start, img, 0, 0); //Cárgala a la ventana la imagen
    for (size_t x = 0; x < img->width; x++)
	{
		for (size_t y = 0; y < img->height; y++)
		{
			mlx_put_pixel(img, x, y, get_rgba(255, 0, 0, 255));
		}
	}	
	mlx_loop(mlx_start); //Arranca el bucle de la pantalla
	mlx_terminate(mlx_start); // Cierra todo cuando se hace click en cerrar
	return (0);
}

/*mlx_set_setting(MLX_STRETCH_IMAGE, true); //Esto hace que la pantalla se vuelva completa
	mlx_start = mlx_init(512, 512, "FDF", true); //Crea la instancia que lleva el programa
    img = mlx_new_image(mlx_start, 128, 128); //Crea una nueva imagen
    mlx_image_to_window(mlx_start, img, 0, 0); //Cárgala a la ventana la imagen
    mlx_put_pixel(img, 10, 5, get_rgba(181, 0, 185, 255)); //Pinta pixels
	mlx_loop(mlx_start); //Arranca el bucle de la pantalla
	mlx_terminate(mlx_start); // Cierra todo cuando se hace click en cerrar*/
