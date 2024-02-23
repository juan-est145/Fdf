/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:31:09 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/23 13:49:30 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>

typedef enum e_error_msg
{
	INVALID_ARGC,
	INVALID_FILE_EXTENSION,
	FAILURE_TO_OPEN_FILE
}							t_error_msg;

typedef struct s_map_line_read
{
	char					**coord;
	char					*file_line;
	int						x_length;
	struct s_map_line_read	*next;
}							t_map_line_read;

int							get_rgba(int r, int g, int b, int a);
void						ft_print_error_msg(t_error_msg type_of_error);
void						ft_load_matrix(char *path);
#endif
