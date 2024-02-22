/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:10:47 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/22 19:35:17 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

void	ft_print_error_msg(t_error_msg type_of_error)
{
	if (type_of_error == ARGC_INVALID)
		ft_printf("You need to provide the url of the map as an argument\n");
	else if (type_of_error == INVALID_FILE_EXTENSION)
		ft_printf("Invalid file extension\n");
	exit(1);
}
