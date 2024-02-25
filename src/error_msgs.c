/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:10:47 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/25 19:30:38 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

void	print_error_msg(t_error_msg type_of_error)
{
	if (type_of_error == INVALID_ARGC)
		ft_printf("You need to provide the url of the map as an argument\n");
	else if (type_of_error == INVALID_FILE_EXTENSION)
		ft_printf("Invalid file extension\n");
	else if (type_of_error == FAILURE_TO_OPEN_FILE)
		ft_printf("Couldn't open file, ensure that the path is correct\n");
	else if (type_of_error == MALLOC_ERROR)
		ft_printf("Error allocating memmory, exiting program\n");
	exit(1);
}
