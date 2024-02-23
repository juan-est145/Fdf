/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:31:09 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/23 15:59:41 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <stdio.h>

typedef enum e_error_msg
{
	INVALID_ARGC,
	INVALID_FILE_EXTENSION,
	FAILURE_TO_OPEN_FILE,
	MALLOC_ERROR
}							t_error_msg;

typedef struct s_map_line_read
{
	char					**coord;
	char					*file_line;
	unsigned int			x_length;
	struct s_map_line_read	*next;
}							t_map_line_read;

int							get_rgba(int r, int g, int b, int a);
void						print_error_msg(t_error_msg type_of_error);
void						load_matrix(char *path);

// Auxilary functions for my different structs
void						add_line_node_to_list(t_map_line_read **head,
								t_map_line_read *new);
t_map_line_read				*create_line_node(void);
void						free_map_line(t_map_line_read **head);
void						malloc_error(t_map_line_read **head);
unsigned int				get_x_length(t_map_line_read *node);
#endif
