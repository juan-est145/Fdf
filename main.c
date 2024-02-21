/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:36 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/21 19:42:00 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// clang -Wall -Werror -Wextra main.c ./MLX42/build/libmlx42.a -ldl
//-lglfw -I include -lglfw -L "/Users/juestrel/.brew/opt/glfw/lib/" -lm

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"

/*void	ft_leaks(void)
{
	system("leaks -q a.out");
}
atexit(ft_leaks);*/

int	main(void)
{
	mlx_t	*mlx_start;

	mlx_set_setting(MLX_MAXIMIZED, true); //Esto hace que la pantalla se vuelva completa
	mlx_start = mlx_init(960, 540, "FDF", true);
	mlx_loop(mlx_start);
	mlx_terminate(mlx_start);
	return (0);
}
