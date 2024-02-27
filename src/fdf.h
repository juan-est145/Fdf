/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:31:09 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/27 18:46:56 by juestrel         ###   ########.fr       */
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
	MALLOC_ERROR,
	MLX_INIT_FAILURE
}							t_error_msg;

typedef struct s_map_line_read
{
	char					**coord;
	char					*file_line;
	unsigned int			x_length;
	struct s_map_line_read	*next;
}							t_map_line_read;

typedef struct s_coord
{
	int						value_of_z;
	bool					color_present;
	int						color;
	bool					end_of_row;
}							t_coord;

typedef struct s_map_data
{
	t_coord					**map;
	unsigned int			height;
	unsigned int			width;
}							t_map_data;

void						print_error_msg(t_error_msg type_of_error);
unsigned int				load_matrix(char *path, t_map_data **map_data,
								t_coord ***map);
void						check_for_colors(char *matrix_string, t_coord *map);
void						input_to_screen(t_map_data **map_data);

// Auxilary functions for my different structs
void						add_line_node_to_list(t_map_line_read **head,
								t_map_line_read *new);
t_map_line_read				*create_line_node(void);
void						free_map_line(t_map_line_read **head);
void						malloc_error(t_map_line_read **head, t_coord **map,
								t_map_data **map_data);
unsigned int				get_x_length(t_map_line_read *node);
void						destroy_map_data(t_coord **map,
								t_map_data **map_data);

// Functions for colors
int							get_rgba(int r, int g, int b, int a);
int							get_r(int rgba);
int							get_g(int rgba);
int							get_b(int rgba);
int							get_a(int rgba);
#endif
