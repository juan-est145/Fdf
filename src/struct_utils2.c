/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:46 by juestrel          #+#    #+#             */
/*   Updated: 2024/02/25 19:31:22 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "../Ultimate_Libft/libft.h"
#include "fdf.h"

void	destroy_map_data(t_coord **map, t_map_data **map_data)
{
	if ((**map_data).height > 0)
	{
		(**map_data).height -= 1;
		while ((**map_data).height != 0)
		{
			free(map[(**map_data).height]);
			(**map_data).height--;
		}
	}
	free(map[(**map_data).height]);
	if (map != NULL)
		free(map);
	if (*map_data != NULL)
		free(*map_data);
}
