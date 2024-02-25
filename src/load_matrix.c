/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:19:24 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/25 19:31:02 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

static int		process_map_file(t_map_line_read **head, int fd,
					unsigned int *y_counter);
static void		create_matrix_of_coord(t_map_line_read **head, t_coord **map,
					t_map_data **map_data);
static void		update_info(t_coord map, char *matrix_string);
static void		free_map_columns(t_coord **map,
					unsigned int row_where_malloc_failed);

unsigned int	load_matrix(char *path, t_map_data **map_data, t_coord **map)
{
	int				fd;
	t_map_line_read	*head;
	unsigned int	y_counter;

	head = NULL;
	y_counter = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error_msg(FAILURE_TO_OPEN_FILE);
	if (process_map_file(&head, fd, &y_counter) == -1)
		malloc_error(&head, map, map_data);
	close(fd);
	map = (t_coord **)malloc(sizeof(t_coord *) * y_counter);
	if (map == NULL)
		malloc_error(&head, map, map_data);
	create_matrix_of_coord(&head, map, map_data);
	free_map_line(&head);
	return (y_counter);
}

static int	process_map_file(t_map_line_read **head, int fd,
		unsigned int *y_counter)
{
	t_map_line_read	*new_node;

	while (1 == 1)
	{
		new_node = create_line_node();
		if (new_node == NULL)
			return (-1);
		new_node->file_line = get_next_line(fd);
		if (new_node->file_line == NULL)
			return (free(new_node), 0);
		new_node->coord = ft_split(new_node->file_line, ' ');
		free(new_node->file_line);
		new_node->file_line = NULL;
		if (new_node->coord == NULL)
			return (free(new_node), -1);
		new_node->x_length = get_x_length(new_node);
		add_line_node_to_list(head, new_node);
		(*y_counter)++;
	}
	return (0);
}

static void	create_matrix_of_coord(t_map_line_read **head, t_coord **map,
		t_map_data **map_data)
{
	t_map_line_read	*temp;
	unsigned int	y;
	unsigned int	x;

	temp = *head;
	y = 0;
	while (temp != NULL)
	{
		x = 0;
		map[y] = (t_coord *)malloc(sizeof(t_coord) * temp->x_length);
		if (map[y] == NULL)
		{
			free_map_columns(map, y);
			malloc_error(head, map, map_data);
		}
		while (temp->coord[x] != NULL && temp->coord[x][0] != '\n')
		{
			update_info(map[y][x], temp->coord[x]);
			check_for_colors(temp->coord[x], map[y][x]);
			x++;
		}
		map[y][x - 1].end_of_row = true;
		temp = temp->next;
		y++;
	}
}

static void	update_info(t_coord map, char *matrix_string)
{
	map.value_of_z = ft_atoi(matrix_string);
	map.end_of_row = false;
}

static void	free_map_columns(t_coord **map,
		unsigned int row_where_malloc_failed)
{
	if (row_where_malloc_failed > 0)
	{
		row_where_malloc_failed -= 1;
		while (row_where_malloc_failed > 0)
		{
			free(map[row_where_malloc_failed]);
			row_where_malloc_failed--;
		}
		free(map[row_where_malloc_failed]);
	}
}

// Tester function for checking that the read is successful
/*static void	tester(t_map_line_read **head); // Erase later

static void	tester(t_map_line_read **head)
{
	unsigned int	i;

	while (*head != NULL)
	{
		i = 0;
		while ((*head)->coord[i] != NULL)
		{
			ft_printf("%s", (*head)->coord[i]);
			ft_printf(" ");
			i++;
		}
		*head = (*head)->next;
	}
}
*/

/*static void	second_tester(t_coord **map, unsigned int y_length);
		// Erase later

static void	second_tester(t_coord **map, unsigned int y_length)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	x = 0;
	while (y < y_length)
	{
		ft_printf("%i", map[y][x].value_of_z);
		ft_printf(" ");
		if (map[y][x].end_of_row == true)
		{
			x = 0;
			y++;
			ft_printf("\n");
		}
		else
			x++;
	}
}
*/