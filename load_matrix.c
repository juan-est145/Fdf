/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:19:24 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/23 13:56:06 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"
#include <fcntl.h>

//Need to malloc the nodes and add functions to add the nodes to a list

void	ft_load_matrix(char *path)
{
	int				fd;
	t_map_line_read	*line_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_print_error_msg(FAILURE_TO_OPEN_FILE);
	while (1 == 1)
	{
		line_read->file_line = get_next_line(fd);
		if (line_read->file_line == NULL)
			break ;
		line_read->coord = ft_split(line_read->file_line, ' ');
		free(line_read->file_line);
		line_read = line_read->next;
	}
	close(fd);
}
