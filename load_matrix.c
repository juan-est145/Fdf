/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:19:24 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/25 13:58:48 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

static void	process_map_file(t_map_line_read **head, int fd,
				unsigned int *y_counter);
static void	create_matrix_of_coord(t_map_line_read **head, t_coord **map);

void	load_matrix(char *path)
{
	int				fd;
	t_map_line_read	*head;
	unsigned int	y_counter;
	t_coord			**map;

	head = NULL;
	y_counter = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error_msg(FAILURE_TO_OPEN_FILE);
	process_map_file(&head, fd, &y_counter);
	close(fd);
	map = (t_coord **)malloc(sizeof(t_coord *) * y_counter);
	if (map == NULL)
		malloc_error(&head);
	create_matrix_of_coord(&head, map);
	free_map_line(&head);
}

static void	process_map_file(t_map_line_read **head, int fd,
		unsigned int *y_counter)
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
		(*y_counter)++;
	}
}

static void	create_matrix_of_coord(t_map_line_read **head, t_coord **map)
{
	t_map_line_read	*temp;
	unsigned int	y;
	unsigned int	x;
	unsigned int	number_str_index;

	temp = *head;
	y = 0;
	while (temp != NULL)
	{
		x = 0;
		number_str_index = 0;
		map[y] = (t_coord *)malloc(sizeof(t_coord) * temp->x_length);
		while (temp->coord[number_str_index] != NULL
			&& temp->coord[number_str_index][0] != '\n')
		{
			map[y][x].value_of_z = ft_atoi(temp->coord[number_str_index]);
			check_for_colors(temp->coord[number_str_index], map[y][x]);
			map[y][x].end_of_row = false;
			x++;
			number_str_index++;
		}
		map[y][x - 1].end_of_row = true;
		temp = temp->next;
		y++;
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