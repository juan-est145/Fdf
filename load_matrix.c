/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:19:24 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/23 16:01:00 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

// Need to malloc the nodes and add functions to add the nodes to a list

static void	process_map_file(t_map_line_read **head, int fd);

void	load_matrix(char *path)
{
	int				fd;
	t_map_line_read	*head;

	head = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error_msg(FAILURE_TO_OPEN_FILE);
	process_map_file(&head, fd);
	close(fd);
}

static void	process_map_file(t_map_line_read **head, int fd)
{
	t_map_line_read	*new_node;

	while (1 == 1)
	{
		new_node = create_line_node();
		if (new_node == NULL)
			malloc_error(head);
		new_node->file_line = get_next_line(fd);
		if (new_node->file_line == NULL)
		{
			free(new_node);
			break ;
		}
		new_node->coord = ft_split(new_node->file_line, ' ');
		free(new_node->file_line);
		new_node->file_line = NULL;
		if (new_node->coord == NULL)
		{
			free(new_node);
			malloc_error(head);
		}
		new_node->x_length = get_x_length(new_node);
		add_line_node_to_list(head, new_node);
	}
}
