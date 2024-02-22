/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:31:09 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/22 19:37:41 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>

typedef enum e_error_msg
{
	INVALID_ARGC,
	INVALID_FILE_EXTENSION
}		t_error_msg;

int		get_rgba(int r, int g, int b, int a);
void	ft_print_error_msg(t_error_msg type_of_error);
#endif
