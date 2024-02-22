/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions-for-colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:29:52 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/22 16:44:49 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ultimate_Libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"
#include "fdf.h"

//This function allows to return the color that you want using rgba encoding.
//The individual bits are moved to their corresponding channel (red, green, blue or alpha)
//and returns a integer codified with said values.
//The '|' operator here allows us to combine the values in a single integer
//For each of the int parameters, just use values between 0 and 255
int get_rgba(int r, int g, int b, int a) 
{
    return (r << 24 | g << 16 | b << 8 | a);
}