/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:31:54 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/23 17:03:31 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include "Ultimate_Libft/libft.h"
#include "fdf.h"

void	add_line_node_to_list(t_map_line_read **head, t_map_line_read *new)
{
	t_map_line_read	*temp;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		return ;
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

t_map_line_read	*create_line_node(void)
{
	t_map_line_read	*new_node;

	new_node = (t_map_line_read *)malloc(sizeof(t_map_line_read));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->coord = NULL;
	new_node->file_line = NULL;
	new_node->x_length = 0;
	return (new_node);
}

void	free_map_line(t_map_line_read **head)
{
	t_map_line_read	*temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		if (temp->file_line != NULL)
		{
			free(temp->file_line);
			temp->file_line = NULL;
		}
		if (temp->coord != NULL)
		{
			free(temp->coord);
			temp->coord = NULL;
		}
		free(temp);
	}
}

void	malloc_error(t_map_line_read **head)
{
	free_map_line(head);
	print_error_msg(MALLOC_ERROR);
}

unsigned int	get_x_length(t_map_line_read *node)
{
	unsigned int	i;

	i = 0;
	while (node->coord[i] != NULL && ft_strncmp(node->coord[i], "\n", 1) != 0)
		i++;
	return (i);
}
