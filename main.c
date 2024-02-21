/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:36 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/21 20:19:11 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -Wall -Werror -Wextra main.c ./MLX42/build/libmlx42.a -ldl
//-lglfw -I include -lglfw -L "/Users/juestrel/.brew/opt/glfw/lib/" -lm

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include  <stdio.h> // Borrar luego

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
    img = mlx_new_image(mlx_start, 128, 128); //Crea una nueva imagen
    mlx_image_to_window(mlx_start, img, 0, 0); //Cárgala a la ventana la imagen
    mlx_put_pixel(img, 10, 5, 0xEDCE9B); //Pinta pixels
	mlx_loop(mlx_start); //Arranca el bucle de la pantalla
	mlx_terminate(mlx_start); // Cierra todo cuando se hace click en cerrar
	return (0);
}
